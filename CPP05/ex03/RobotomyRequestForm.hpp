#pragma once

# include "AForm.hpp"
# include <cstdlib> //| rand

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		virtual void execute(const Bureaucrat &executor) const;
	
	private:
		std::string _target;
};
