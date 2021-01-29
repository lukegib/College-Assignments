var localStrategy = require('passport-local').Strategy;
var User = require('../models/users');

module.exports = (passport) => {
    passport.serializeUser((user, done) => {
        done(null, user);
    });

    passport.deserializeUser((user, done) => {
        done(null, user);
    });

    passport.use(new localStrategy((username, password, done) => {
        User.findOne({username: username}, (err, doc) => {
          if(err) {
            done(err);
          } else {
            if(doc) {
              var validPassword = doc.comparePassword(password, doc.password);
              if(validPassword) {
                done(null, {
                  username: doc.username,
                  password: doc.password
                });
              } else {
                done(null, false);
              }
            } else {
              done(null, false);
            }
          }
        })
    }));
}
