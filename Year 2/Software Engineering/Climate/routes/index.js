var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  if(req.user) {
    res.render('index', {
      linkText: "Rooms",
      name: req.user.username,
      link: "/users?name=" + req.user.username,
      isLoggedIn: true
    });
  } else {
    res.render('index', {
      linkText: "Log in",
      link: "/login",
      isLoggedIn: false
    });
  }
});

router.get('/login', function(req, res, next) {
  res.render('login');
});

module.exports = router;
