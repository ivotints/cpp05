/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:19:29 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/11 20:18:29 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string _name;
		const std::string _target;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
		AForm();
		virtual void executeConcrete() const = 0;

	public:
		AForm(std::string name, std::string target, int signGrade, int executeGrade);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		const std::string	&getName() const;
		const std::string	&getTarget() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		class UnsignedFormException : public std::exception
		{
			const char *what() const throw();
		};
		void beSigned(const Bureaucrat &src);
		void execute(Bureaucrat const &executor) const;

};

std::ostream &operator<<(std::ostream &out, const AForm &src);




