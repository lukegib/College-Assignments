'use strict'

var isAdmin;
const room = window.location.pathname.substring(window.location.pathname.lastIndexOf('/') + 1);

/*
╔══════════════════════════════╗
        Signalling Server
╚══════════════════════════════╝
*/

const socket = io.connect('/room');
const signalMessage = (message) => {
  socket.emit('message', message, room);
}


//Signalling Rooms
socket.on('created', (room, clientID) => {
  isAdmin = true;
});

socket.on('joined', (room, clientID) => {
  isAdmin = false;
  createPeerConnection(isAdmin);
});

socket.on('full', (room) => {
  alert('Room : ' + room + ' is Full. A new Room will be created for you');
  window.location.replace("http://localhost:3000/room");
});

socket.on('ready', () => {
  createPeerConnection(isAdmin);
});

socket.on('message', (message) => {
  signalledMessageCallback(message);
});

socket.emit('create or join', room);

socket.on('quit', () => {
  
});

window.addEventListener('unload', () => {
  socket.emit('quit', room, isAdmin);
});

const getIsAdmin = () => {
  return isAdmin;
}
