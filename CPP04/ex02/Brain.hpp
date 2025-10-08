#pragma once

# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);

	private:
		std::string _ideas[100];
};
