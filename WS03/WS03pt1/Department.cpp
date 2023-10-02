#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }
    void Department::updateName(const char* newname)
    {
        if (newname != nullptr && strlen(newname) != 0)
        {
                delete[] name;
                name = new char[strlen(newname)+1];
                strcpy(name, newname);
        }
    }
    void Department::updateBudget(double change) {
        if (change && change > 0) {
            budjet += change;
        }
    }
    bool Department::addProject(Project& newproject)
    {
        double newCost = newproject.m_cost;
        double totalCost = 0;
        for (int i = 0; i < currentproject; i++)
        {
            totalCost += project[i].m_cost;
        }
        if (totalCost + newCost <= budjet)
        {
            Project* temp = new Project[currentproject + 1];
            for (int i = 0; i < currentproject; i++)
                temp[i] = project[i];
            temp[currentproject] = newproject;
            delete[]project;
            project = temp;
            currentproject++;
            return true;
        }
        return false;
    }
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }
    Project* Department::fetchProjects() const
    {
        return project;
    }
    int Department::fetchNumProjects() const {
        return currentproject;
    }
    double Department::totalexpenses() {
        double total = 0;
        for (int i = 0; i < this->currentproject; i++) {
            total += project[i].m_cost;
        }
        return total;
    }
    double Department::remainingBudget() {
        return budjet - totalexpenses();
    }
    double Department::fetchBudget() const {
        return budjet;
    }
    void Department::clearDepartment()
    {
        if (name != nullptr) {
            delete[] name; name = nullptr;
        }
        if (project != nullptr) {
            delete[] project; 
            project = nullptr;
        }
        currentproject = 0;
        budjet =15345.99;
    }
    char* Department:: fetchName() const {
        return name;
    }
}