#pragma once

# include <string>

class Harl
{
	public:
		Harl(); //| Construtor
		~Harl(); //| Destrutor

		//|----------| Método |----------|//
		void complain( std::string level );

	private:
		void debug( void ) const;
		void info( void ) const ;
		void warning( void ) const;
		void error( void ) const;
};
