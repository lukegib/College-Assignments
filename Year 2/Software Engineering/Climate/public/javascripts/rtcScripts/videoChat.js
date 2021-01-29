'use strict'

//connection variables
var peerConn;
var channelReady = false;

const config = {
  bundlePolicy: "balanced",
  iceServers: [{
    'urls': 'stun:stun.l.google.com:19302'
  }]
};

//rtc stream variables
var localStream;
var remoteStream;

var streamOn = false;
const sdpConstraints = {
  audio: true,
  video: true
}

//Client side elements
var localVideo;
var remoteVideo;
var mediaControls;



/*
╔══════════════════════════════╗
       WebRTC Connection
╚══════════════════════════════╝
*/



const signalledMessageCallback = (message) => {
  if(message === 'got user media') {
      startStream();

  } else if (message.type === 'offer') {
      if(!getIsAdmin() && !streamOn) {
        startStream();
      }

      //Signalling answer callback
      peerConn.setRemoteDescription(new RTCSessionDescription(message), () => {}, logError);
      peerConn.createAnswer(onLocalSessionCreated, logError);

  } else if (message.type === 'answer' && streamOn) {
      //answer callback
      peerConn.setRemoteDescription(new RTCSessionDescription(message), () => {}, logError);

  } else if (message.type === 'candidate' && streamOn) {
      peerConn.addIceCandidate(new RTCIceCandidate({candidate: message.candidate}));

  } else if (message === 'user disconnected') {
      stopStream();

    if(!isAdmin) {
      location.reload();
    }
  } else if(message === 'page refresh') {
      stopStream();
      handlePageRefresh();
  }
}

const createPeerConnection = (isAdmin) => {
  //the channel is ready for streaming after a peer joins.
  try {

    peerConn = new RTCPeerConnection(config);

    //Sending iceCandidate
    peerConn.onicecandidate = (event) => {
      if (event.candidate) {
        signalMessage({
          type: 'candidate',
          label: event.candidate.sdpMLineIndex,
          id: event.candidate.sdpMid,
          candidate: event.candidate.candidate
        });
      }
    };

    channelReady = true;

  } catch(error) {
      alert('Connection error : ' + error.toString());
  }


  //Remote streams
  peerConn.onaddstream = (event) => {
    remoteStream = event.stream;
    remoteVideo.srcObject = remoteStream;
    remoteVideo.play();
  }
}

const logError = (err) => {
  if (!err) return;
  if (typeof err === 'string') {
    console.warn(err);
  } else {
    console.warn(err.toString(), err);
  }
}



/*
╔══════════════════════════════╗
       Media Handling
╚══════════════════════════════╝
*/



window.onload = () => {

  localVideo = document.getElementById('userVid');
  remoteVideo = document.getElementById('guestVid');
  mediaControls = {
    pauseVideo: document.getElementById('pauseVideo'),
    muteSound: document.getElementById('muteSound')
  };

  mediaControls.pauseVideo.onclick = () => {
    let stream;
    let videoTracks;

    if($('#iconCont').css("background-color") == "rgb(30, 144, 255)") {
      stream = remoteVideo.srcObject;
      videoTracks = stream.getVideoTracks();
      videoTracks.forEach((track) => track.enabled = !track.enabled);
    } else {
      stream = localVideo.srcObject;
      videoTracks = stream.getVideoTracks();
      videoTracks.forEach((track) => track.enabled = !track.enabled);
    }
  }

  mediaControls.muteSound.onclick = () => {
    let stream;
    let audioTracks;

    //for some reason the audio is switched around; local audio is actually remote audio, vice versa
    if($('#iconCont').css("background-color") == "rgb(30, 144, 255)") {
      stream = localVideo.srcObject;
      audioTracks = stream.getAudioTracks();
      audioTracks.forEach((track) => track.enabled = !track.enabled);
    } else {
      stream = remoteVideo.srcObject;
      audioTracks = stream.getAudioTracks();
      audioTracks.forEach((track) => track.enabled = !track.enabled);
    }
  }
}


navigator.mediaDevices.getUserMedia(sdpConstraints)
.then((stream) => {
  localStream = stream;
  localVideo.srcObject = localStream;
  localVideo.play();
  localVideo.muted = true;
  signalMessage('got user media');
  if(getIsAdmin()) startStream();
})
.catch((error) => {
  if(channelReady) {
    location.reload();
  } else {
    alert('getUserMedia error: ' + error.name);
  }
});

const startStream = () => {
    if(!streamOn && typeof localStream !== 'undefined' && channelReady) {
      peerConn.addStream(localStream);
      streamOn = true;
      //create offer
      if(getIsAdmin()) {
        peerConn.createOffer(onLocalSessionCreated, logError);
      }
    }
}

const stopStream = () => {
  //nullify the rtc Connection
  streamOn = false;
  peerConn.close();
  peerConn = null;
}

//a user can refresh a page but stay in the room and continue streaming
const handlePageRefresh = () => {
  streamOn = true;
  createPeerConnection(isAdmin);
}

const onLocalSessionCreated = (description) => {
  peerConn.setLocalDescription(description, () => {
    signalMessage(peerConn.localDescription);
  }, logError);
}

window.onbeforeunload = () => {
  signalMessage('user disconnected');
}

window.unload = () => {
  signalMessage('page refresh');
}
