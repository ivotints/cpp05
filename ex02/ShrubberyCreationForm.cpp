/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:53 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/11 20:32:58 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery creation form", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeConcrete() const
{
	std::srand(std::time(0));
	int r = std::rand() % 3;
	std::ofstream file((_target + "_shrubbery").c_str());

	if (!file)
	{
		std::cerr << "Error: Could not create file " << _target << "_shrubbery\n";
		return ;
	}
	if (r == 0)
	{
		file << "       ###\n";
		file << "      #o###\n";
		file << "    #####o###\n";
		file << "   #o#\\#|#/###\n";
		file << "    ###\\|/#o#\n";
		file << "     # }|{  #\n";
		file << "       }|{\n";
		file.close();
	}
	else if (r == 1)
	{
		file << "        v\n";
		file << "       >X<\n";
		file << "        A\n";
		file << "       d$b\n";
		file << "     .d\\$$b.\n";
		file << "   .d$i$$\\$$b.\n";
		file << "      d$$@b\n";
		file << "     d\\$$$ib\n";
		file << "   .d$$$\\$$$b\n";
		file << " .d$$@$$$$\\$$ib.\n";
		file << "     d$$i$$b\n";
		file << "    d\\$$$$@$b\n";
		file << " .d$@$$\\$$$$$@b.\n";
		file << ".d$$$$i$$$\\$$$$$$b.\n";
		file << "        ###\n";
		file << "        ###\n";
		file << "        ###\n";
	}
	else
	{
		file << "       ccee88oo\n";
		file << "  C8O8O8Q8PoOb o8oo\n";
		file << " dOB69QO8PdUOpugoO9bD\n";
		file << "CgggbU0OU qOp qOdoUOdcb\n";
		file << "   6OuU  /p u gcoUodpP\n";
		file << "      \\\\//  /douUP\n";
		file << "        \\\\////\n";
		file << "         |||/\\\n";
		file << "         |||\\/\n";
		file << "         |||||\n";
		file << "   .....//||||\\....\n";
	}
	std::cout << "Shrubbery created in " << _target << "_shrubbery\n";
}
