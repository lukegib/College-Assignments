const createError = require('http-errors');
const express = require('express');
const exphbs = require('express-handlebars');
const expressValidator = require('express-validator');
const path = require('path');
const cookieParser = require('cookie-parser');
const bodyParser = require('body-parser');
const logger = require('morgan');
const socketio = require('socket.io');
const bcrypt = require('bcryptjs');
const mongodb = require('mongodb');
const mongoose = require('mongoose');
const session = require('express-session');
const passport = require('passport');

const db = mongoose.connection;
require('./config/passport')(passport);


const indexRouter = require('./routes/index');
const usersRouter = require('./routes/users');
const roomsRouter = require('./routes/rooms');
const authRouter = require('./routes/auth')(passport);

const app = express();
const io = socketio();
app.io = io;


// view engine setup
app.set('views', path.join(__dirname, 'views'));
//app.set('view engine', 'jade');
app.engine('handlebars', exphbs({defaultLayout: 'main'}));
app.set('view engine', 'handlebars');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: false}));
app.use(express.static(path.join(__dirname, 'public')));
app.use(session({
  secret: 'dTaKnzuU72dNaWm1',
  saveUninitialized: false,
  resave: false
}));
app.use(passport.initialize());
app.use(passport.session());
app.use(expressValidator());


app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/rooms', roomsRouter);
app.use('/auth', authRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});


module.exports = app;
