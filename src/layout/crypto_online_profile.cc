/**
 * @file crypto_online_profile.cc
 * @date 11/01/2017
 *
 * @brief This handles the definitions defined in the related header file.
 * It handles the loading of the user profiles and all related user profile data that needs to be shown to the user.
 *
 *
 * @author Jacob Powell
 */

#include "crypto_online_profile.h"
#include "crypto_online_home.h"

/**
 * @brief The Constructor for the CryptoOnlineProfile class
 * The constructor handles the initial connection to the database. Once connected it figures out what user it is that
 * has logged on and collects the user information on that profile loading it into a member of the class. It then
 * loads that information and displays it on the screen.
 *
 * It also checks to see if there is actually a user logged in to the system. If there isn't then it displays to the
 * viewer that there is no user currently logged in.
 */
CryptoOnlineProfile::CryptoOnlineProfile(Session& session) : _current_session(session),
                                                             database_interface(session)
{
   if(this->_current_session.login().loggedIn())
       load_profile_page_logged_in();
   else{
       load_profile_page_logged_out();
   }
}

void CryptoOnlineProfile::load_profile_page_logged_in() {
    const Wt::Auth::User& user = _current_session.login().user();

    this->_username_label = this->elementAt(0,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>("Username:"));
    this->_username_label->setStyleClass("profile_username");

    this->_username = this->elementAt(0,1)->addWidget(Wt::cpp14::make_unique<Wt::WText>(" " + user.identity(Wt::Auth::Identity::LoginName)));
    this->_username->setStyleClass("profile_username");
}

void CryptoOnlineProfile::load_profile_page_logged_out() {
    this->_username_label = this->elementAt(0,0)->addWidget(Wt::cpp14::make_unique<Wt::WText>("No User Logged In"));
    this->_username_label->setStyleClass("profile_username");
}

