/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/10/06 14:54:54 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	{
		Bureaucrat igor;
		Form form;

		std::cout << form;
		std::cout << igor;
		igor.signForm(form);
		igor.signForm(form);
	}
	std::cout << std::endl;
	{
		Bureaucrat igor("Igor", 50);
		Form form("Pass", 60, 150);

		std::cout << form;
		std::cout << igor;
		igor.signForm(form);
		igor.signForm(form);
		igor.signForm(form);
		std::cout << form;

	}
	std::cout << std::endl;
	{
		Bureaucrat igor("Igor", 100);
		Form form("Pass", 60, 150);

		std::cout << form;
		std::cout << igor;
		igor.signForm(form);
		igor.signForm(form);
		igor.signForm(form);
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat igor("Igor", 100);
		Form form("Pass", 60, 150);

		std::cout << form;
		std::cout << igor;
		form.beSigned(igor);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "EXCEPTION!\n";
	}
}
