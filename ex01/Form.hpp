/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:19:29 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/11 15:30:36 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;

	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		const std::string &getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		void beSigned(const Bureaucrat &src);
};

std::ostream &operator<<(std::ostream &out, const Form &src);



