/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/10/06 12:35:34 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *buro[3];

	buro[0] = new Bureaucrat();
	buro[1] = new Bureaucrat("John", 1);
	buro[2] = new Bureaucrat(*buro[0]);
	for (int i = 0; i < 3; i++)
	{
		std::cout << *buro[i];
		delete buro[i];
	}
	std::cout << std::endl;



	try
	{
		Bureaucrat igor("Igor", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat igor("Igor", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;



	try
	{
		Bureaucrat igor("Igor", 146);
		for (;;)
		{
			std::cout << igor;
			igor.decrementGrade();
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;



	try
	{
		Bureaucrat igor("Igor", 5);
		for (;;)
		{
			std::cout << igor;
			igor.incrementGrade();
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
