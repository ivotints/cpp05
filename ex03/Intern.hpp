/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:06:10 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/12 14:35:57 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
	private:
		static AForm* createShrubberyForm(const std::string &target);
		static AForm* createRobotomyForm(const std::string &target);
		static AForm* createPresidentialPardonForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);
};
