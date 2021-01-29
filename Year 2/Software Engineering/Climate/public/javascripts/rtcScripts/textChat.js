'use strict'


/*
╔══════════════════════════════╗
       WebRTC Connection
╚══════════════════════════════╝
*/


const config = {
  bundlePolicy: "balanced",
  iceServers: [{
    'urls': 'stun:stun.l.google.com:19302'
  }]
};

//connection variables
var peerConn;
var dataChannel;

//Client side elements
var sendButton;
var textBox;
var localName;
var remoteName
var chatTable;

const signalledMessageCallback = (message) => {
  if (message.type === 'offer') {
      peerConn.setRemoteDescription(new RTCSessionDescription(message), () => {}, logError);
      peerConn.createAnswer(onLocalSessionCreated, logError);

  } else if (message.type === 'answer') {
      peerConn.setRemoteDescription(new RTCSessionDescription(message), () => {}, logError);

  } else if (message.type === 'candidate') {
      peerConn.addIceCandidate(new RTCIceCandidate({candidate: message.candidate}));

  } else if(message === 'user disconnected') {
      dataChannel.close();

  } else if(message.includes('remoteName changed')) {
      remoteName.value = message.split(' ').splice(2).join(" ");

  } else if(message === 'user is typing') {
    $('#userTyping').html("Typing...");
      $('#userTyping').show();

  } else if(message === 'user not typing') {
      $('#userTyping').hide();
  }
}

const createPeerConnection = (isAdmin) => {
  peerConn = new RTCPeerConnection(config);

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

  if (isAdmin) {
    dataChannel = peerConn.createDataChannel('channel', {ordered: true});
    onDataChannelCreated(dataChannel);
    peerConn.createOffer(onLocalSessionCreated, logError);

  } else {
    peerConn.ondatachannel = (event) => {
      dataChannel = event.channel;
      onDataChannelCreated(dataChannel);
      };
    }
}


const onLocalSessionCreated = (description) => {
  peerConn.setLocalDescription(description, () => {
    signalMessage(peerConn.localDescription);
  }, logError);
}

const onDataChannelCreated = (channel) => {
  channel.onopen = handleChannelOpenedEvent;
  channel.onclose = handleChannelClosedEvent;
  channel.onmessage = receiveData();
}

const logError = (err) => {
  if (!err) return;
  if (typeof err === 'string') {
    console.warn(err);
  } else {
    console.warn(err.toString(), err);
  }
}

const sendText = (text) => {
  dataChannel.send(text);
}



/*
╔══════════════════════════════╗
        Chat Handling
╚══════════════════════════════╝
*/


window.onload = () => {
  sendButton = document.getElementById('send');
  textBox = document.getElementById('inputText');
  localName = document.getElementById('localName');
  remoteName = document.getElementById('remoteName');
  chatTable = document.getElementById('testFlex');

  textBox.onkeyup = (e) => {
    if(e.keyCode == 13 && !e.shiftKey) {
        e.preventDefault();
        sendButton.click();
    }

    if(textBox.value.length > 0) {
      console.log("user is typing");
        signalMessage('user is typing');
    } else {
        signalMessage('user not typing');
    }
  }

  $('#userTyping').hide();

  $("#localName").blur(() => {
    signalMessage('remoteName changed ' + localName.value);
  });

  sendButton.onclick = () => {
    if(textBox.value != "") {
      sendText(textBox.value);
      displayMessageSent(textBox.value);
      textBox.value = "";
      textBox.focus();
      signalMessage('user not typing');
    }
  }
}

//utility function to display connection status
const handleChannelClosedEvent = () => {
  $("#testFlex").empty();
  sendButton.disabled = true;
  chatTable.innerHTML += "<div id='messageCont'><p id='message' class='userMes'>" + "Disconnected" + "</p></div>";
}

//utility function to display connection status
const handleChannelOpenedEvent = () => {
  sendButton.disabled = false;
  chatTable.innerHTML += "<div id='messageCont'><p id='message' class='userMes'>" + "connected" + "</p></div>";
}

//returns a function to display the message
const receiveData = () =>  {
  return function onmessage(event) {
    if (typeof event.data === 'string') {
      displayMessageReceived(event.data);
      return;
    }
  }
}

const displayMessageSent = (message) => {
  //let timeSent = new Date(Date.now()).toString();
  message = message.replace(/</g, "&lt;").replace(/>/g, "&gt;");
  let outgoingHTML = "<div id='messageCont'><p id='message' class='userMes'>" + message + "</p></div>";
  chatTable.innerHTML += outgoingHTML;
}

const displayMessageReceived = (message) => {
  //let timeSent = new Date(Date.now()).toString();
  message = message.replace(/</g, "&lt;").replace(/>/g, "&gt;");
  let incomingHTML = "<div id='messageCont'><p id='message' class='guestMes'>" + message +  "</p></div>";
  chatTable.innerHTML += incomingHTML;
}

window.onbeforeunload = () => {
  dataChannel.close();
  //signalMessage('user disconnected');
}
