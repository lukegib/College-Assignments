var mongoose = require('mongoose');
var bcrypt = require('bcryptjs');

//mongoose.connect('mongodb://XXXXXXX', {useNewUrlParser: true, useCreateIndex: true});
const database = 'mongodb://localhost/climate';
mongoose.connect(database)
     .then( () => console.log(`Connected to ${database}`));


var db = mongoose.connection;

var RoomSchema = mongoose.Schema({
  roomID: {
    type: String,
    index: true
  },
  roomName: {
    type: String
  }
});

var Room = module.exports = mongoose.model('Room', RoomSchema);

module.exports.getRoomById = (id, callback) => {
  var query = {roomID: id};
  Room.findOne(query, callback);
}

module.exports.getRoomByName = (name, callback) => {
  var query = {roomName: name};
  Room.findOne(query, callback);
}

module.exports.createRoom = (newRoom, callback) => {
  if(!newRoom.roomName || newRoom.roomName === '') {
    newRoom.save(callback);

  } else {
      bcrypt.genSalt(10, (err, salt) => {
        bcrypt.hash(newRoom.roomName, salt, (err, hash) => {
          newRoom.roomName = hash;
          newRoom.save(callback);
        });
    });
  }
}

module.exports.deleteRoom = (id, callback) => {
  var query = {roomID: id};
  Room.deleteOne(query, callback);
}
