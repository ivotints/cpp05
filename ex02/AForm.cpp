/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:44:16 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/11 20:18:33 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Ordinary form"), _target("default target"), _signed(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(std::string name, std::string target, int signGrade, int executeGrade) : _name(name), _target(target), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _target(src._target), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	if (src._signGrade < MAX_GRADE || src._executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (src._signGrade > MIN_GRADE || src._executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &src)
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

AForm::~AForm() {}

const std::string &AForm::getName() const
{
	return (_name);
}

const std::string &AForm::getTarget() const
{
	return (_target);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::UnsignedFormException::what() const throw()
{
	return ("Form is unsigned!");
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "Form " << src.getName() << " is ";
	if (src.getSigned() == false)
		out << "not ";
	out << "signed. Sign grade is " << src.getSignGrade() << ". Execute grade is " << src.getExecuteGrade() << ". Target " << src.getTarget() << ".\n";
	return (out);
}

void AForm::beSigned(const Bureaucrat &src)
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

void AForm::execute(Bureaucrat const &executor) const
{
	if (_signed == false)
		throw UnsignedFormException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
	executeConcrete();
}
