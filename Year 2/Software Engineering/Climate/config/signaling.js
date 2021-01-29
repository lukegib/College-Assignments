module.exports = (io) => {
  const roomNsp = io.of('/rooms');
  const Room = require('../models/rooms');


  roomNsp.on('connection', function(socket) {

    socket.on('message', function(message, room) {
      socket.to(room).emit('message', message);
    });

    socket.on('create or join', function(room) {

      if(Room.getRoomById(room, (err, id) => {
        if(err) throw err;
        if(!id) {
          var newRoom = new Room({
            roomID: room,
            roomName: ''
          });
          Room.createRoom(newRoom, (err, room) => {
            console.log("Page refreshed");
            if(err) throw err;
          });
        }
      }));

      let clientsInRoom = roomNsp.adapter.rooms[room];
      let numClients = clientsInRoom ? Object.keys(clientsInRoom.sockets).length : 0;

      if (numClients === 0) {
          socket.join(room);
          socket.emit('created', room, socket.id);
      } else if (numClients === 1) {
          socket.join(room);
          socket.emit('joined', room, socket.id);
          socket.to(room).emit('ready', room);
      } else {
          // max two clients
          socket.emit('full', room);
      }
    });

    socket.on('quit', function(room, isAdmin){
      socket.on('disconnect', function() {
        socket.in(room).emit('quit');

        let numClients = roomNsp.adapter.rooms[room] ? Object.keys(roomNsp.adapter.rooms[room].sockets).length : 0;
        if(isAdmin && numClients == 0) {
          Room.deleteRoom(room, (err, id) => {
            if(err) throw err;
          });
        }
      });
    });
  });
}
