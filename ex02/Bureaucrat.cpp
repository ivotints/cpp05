/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:50 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/11 16:28:54 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Ordinary bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
		*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "\n";
	return (out);
}

const std::string &Bureaucrat::getName(void) const
{
	return (_name);
}

const int &Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// 3 -> 2
void	Bureaucrat::incrementGrade()
{
	if (_grade <= MAX_GRADE)
		throw GradeTooHighException();
	_grade--;
}

// 3 -> 4
void	Bureaucrat::decrementGrade()
{
	if (_grade >= MIN_GRADE)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &src)
{
	if (_grade > src.getSignGrade())
		std::cout << _name << " couldn`t sign " << src.getName() << " because grade is too low.\n";
	else
	{
		if (src.getSigned() == false)
		{
		std::cout << _name << " signed " << src.getName() << "\n";
		}
		src.beSigned(*this);
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	std::cout << _name << " executed " << form.getName() << "\n";
}
