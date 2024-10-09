/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:33:17 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/22 16:21:42 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string formNames[3] = {"Shrubbery creation form", "Robotomy request form", "Presidential pardon form"};
	AForm* (*formCreators[3])(const std::string &target) = {createShrubberyForm, createRobotomyForm, createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << "\n";
			return (formCreators[i](target));
		}
	}
	std::cerr << "Error: Form name '" << name << "' not recognized.\n";
	std::cerr << "Avalible forms:\n";
	for (int i = 0; i < 3; i++)
		std::cerr << formNames[i] << std::endl;
	return (NULL);
}
