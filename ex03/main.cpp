/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/12 14:38:38 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << std::endl;
	Intern someRandomIntern;
	AForm *form = someRandomIntern.makeForm("Shrubbery creation form", "Home");
	if (form)
	{
		std::cout << *form;
		delete form;
	}
}
