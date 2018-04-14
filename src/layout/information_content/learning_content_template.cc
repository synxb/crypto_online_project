/*
 * File: learning_content_template.cc
 * Created: 15/01/2018 14:26
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#include "learning_content_template.h"

#include <Wt/WPushButton.h>
#include <Wt/WLineEdit.h>

learning_content_template::learning_content_template(Session& session, std::string title_link, std::string contents_link, std::string question_link) :
    database_api(session)
{
    this->content_title_link = std::move(title_link);
    this->content_resource_link = std::move(contents_link);
    this->content_question_link = std::move(question_link);
}

learning_content_template::learning_content_template(Session& session, std::string title, std::string contents_link) : database_api(session) {
    this->content_title_link = std::move(title);
    this->content_resource_link = std::move(contents_link);
}

std::unique_ptr<Wt::WTemplate>
learning_content_template::load_question_section(const std::string &template_name, const int question_id[]) {
    std::cout << question_id[0] << std::endl;
    auto result = Wt::cpp14::make_unique<Wt::WTemplate>(Wt::WString::tr(template_name));
    const int question_id_temp[] = {question_id[0], question_id[1]};

    auto* answer_entry_1 = new Wt::WLineEdit();
    auto* answer_entry_2 = new Wt::WLineEdit();
    auto process_answer_button_1 = Wt::cpp14::make_unique<Wt::WPushButton>("Check Answer");
    auto process_answer_button_2 = Wt::cpp14::make_unique<Wt::WPushButton>("Check Answer");


    process_answer_button_1->clicked().connect([=]{
        const std::string &answer_1 = answer_entry_1->text().toUTF8();
        this->database_api.add_answer_to_user(answer_1, question_id_temp[0]);
    });

    process_answer_button_2->clicked().connect([=]{
        const std::string &answer_2 = answer_entry_2->text().toUTF8();
        this->database_api.add_answer_to_user(answer_2, question_id_temp[1]);
    });

    result->bindWidget(std::to_string(question_id[0]), std::unique_ptr<Wt::WLineEdit>(answer_entry_1));
    result->bindWidget(std::to_string(question_id[1]), std::unique_ptr<Wt::WLineEdit>(answer_entry_2));
    result->bindWidget("submit_button_1", std::move(process_answer_button_1));
    result->bindWidget("submit_button_2", std::move(process_answer_button_2));

    return result;
}
