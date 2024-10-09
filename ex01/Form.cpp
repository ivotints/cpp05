/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:44:16 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/11 15:42:30 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Ordinary form"), _signed(false), _signGrade(150), _executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	if (src._signGrade < MAX_GRADE || src._executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (src._signGrade > MIN_GRADE || src._executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &src)
{
	if (src._signGrade < MAX_GRADE || src._executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (src._signGrade > MIN_GRADE || src._executeGrade > MIN_GRADE)
		throw GradeTooLowException();
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return (*this);
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecuteGrade() const
{
	return (_executeGrade);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << "Form " << src.getName() << " is ";
	if (src.getSigned() == false)
		out << "not ";
	out << "signed. Sign grade is " << src.getSignGrade() << ". Execute grade is " << src.getExecuteGrade() << ".\n";
	return (out);
}

void Form::beSigned(const Bureaucrat &src)
{
	if (_signed == false && src.getGrade() <= _signGrade)
		_signed = true;
	else if (_signed == true)
		std::cout << "Form " << _name << " is already signed!\n";
	else
	{
		std::cerr << "Form " << _name << " can not be signed by " << src.getName() << ": ";
		throw GradeTooLowException();
	}
}
