var express = require('express');
var router = express.Router();
var uuidv4 = require('uuid/v4');

var Room = require('../models/rooms');

/* GET Rooms listing.
    Handles GET requests for all Rooms:
      > textChat
      > videoChat
      > fileTransfer
*/



/*
╔══════════════════════════════╗
            Routing
╚══════════════════════════════╝
*/


router.get('/join', (req, res, next) => {
  res.render('joinRoom');
});

router.get('/videoChat', (req, res, next) => {
  res.redirect('videoChat/' + newRoom());
});

router.get('/videoChat/:id', (req, res, next) => {
  findRoom(req.params.id)
  .then(() => res.render('videoChat'))
  .catch(() => res.render('error'));
});

router.get('/textChat', (req, res, next) => {
  res.redirect('textChat/' + newRoom());
});

router.get('/textChat/:id', (req, res, next) => {
  findRoom(req.params.id)
  .then(() => res.render('textChat'))
  .catch(() => res.render('error'));
});

router.get('/fileTransfer', (req, res, next) => {
  res.redirect('fileTransfer/' + newRoom());
});

router.get('/fileTransfer/:id', (req, res, next) => {
  findRoom(req.params.id)
  .then(() => res.render('fileShare'))
  .catch(() => res.render('error'));
});






/*
╔══════════════════════════════╗
            Functions
╚══════════════════════════════╝
*/



const newRoom = () => {
  var newRoom = new Room({
    roomID: uuidv4(),
    roomName: ''
  });

  Room.createRoom(newRoom, (err, room) => {
    if(err) throw err;
  });

  return newRoom.roomID;
}

const findRoom = (roomID) => {
  return new Promise((resolve, reject) => {
    Room.getRoomById(roomID, (err, id) => {
      if(err) reject(new Error(err));
      else if(!id) reject(new Error('Requested Room ID Does not exist'));

      resolve(id);
    });
  });
}

module.exports = router;
