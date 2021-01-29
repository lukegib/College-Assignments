var express = require('express');
var router = express.Router();
var User = require('../models/users');

/*POST listings for authenticating registration and logins*/

module.exports = (passport) => {
  router.post('/signup', (req, res, next) => {
    var body = req.body,
        username = body.username,
        email = body.email,
        password = body.password,
        repassword = body.repassword;

        //express-validation - needs handling
        req.checkBody('username', 'Name Field is Required').notEmpty();
        req.checkBody('email', 'Email field is required').notEmpty();
        req.checkBody('email', 'Invalid Email').isEmail();
        req.checkBody('password', 'Password field is required').notEmpty();
        req.checkBody('password', 'Password must be at least 8 characters long').isLength({min: 8});
        req.checkBody('repassword', 'Passwords do not match').equals(req.body.password);

        var errors = req.validationErrors();

          User.findOne({username: username}, (err, doc) => {
            if(err) {
              res.render('error');
            }
            else {
              if(doc) {
                  //handle username taken
              } else {
                var record = new User();
                record.username = username;
                record.email = email;
                record.password = record.hashPassword(password);

                record.save((err, user) => {
                  if(err) {
                    res.render('error');
                  } else {
                    req.login(record, (err) => {
                      if(err) {
                        res.render('error');
                      } else {
                        return res.redirect('/users?name=' + username);
                      }
                    });
                  }
                });
              }
            }
          });
  });

  router.post('/login', (req, res, next) => {
    passport.authenticate('local', {
      failureRedirect: '/login',
      successRedirect: '/users?name=' + req.body.username
    })(req, res, next);
  });

  return router;
}
