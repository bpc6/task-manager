#include "task-manager/task.h"

#include <string>
#include <utility>

Task::Task(std::string title, std::string dueDate)
    : title(std::move(title)), due(std::move(dueDate)), status("Not Started") {}

Task::Task(std::string title, std::string dueDate, std::string description)
    : title(std::move(title)),
      due(std::move(dueDate)),
      status("Not Started"),
      description(std::move(description)) {}

Task::Task(std::string title, std::string dueDate, std::string status, std::string description)
    : title(std::move(title)),
      due(std::move(dueDate)),
      status(std::move(status)),
      description(std::move(description)) {}

// Getters
std::string Task::getTitle() const { return title; }

std::string Task::getDescription() const { return description; }

std::string Task::getDue() const { return due; }

std::string Task::getStatus() const { return status; }

// Setters
void Task::setTitle(const std::string& newTitle) { title = newTitle; }

void Task::setDescription(const std::string& newDescription) { description = newDescription; }

void Task::setDue(const std::string& newDue) { due = newDue; }

void Task::setStatus(const std::string& newStatus) { status = newStatus; }

std::string Task::toString() {
  return title + ", " + due + ", " + status + ", " + description + ",\n";
}

std::string Task::header() { return "title, due, status, description,\n"; }
