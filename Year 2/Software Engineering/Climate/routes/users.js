var express = require('express');
var router = express.Router();

var loggedin = (req, res, next) => {
  if(req.isAuthenticated()) {
    next();
  } else {
    res.redirect('/login')
  }
}

router.get('/', loggedin, (req, res, next) => {
  res.render('users', {
    name: req.query.name
  });
});

router.get('/logout', (req, res, next) => {
  req.logout();
  res.redirect('/');
});

module.exports = router;
