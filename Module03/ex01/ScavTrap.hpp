/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:17:52 by hvayon            #+#    #+#             */
/*   Updated: 2022/09/28 21:38:23 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &); 
		ScavTrap    &operator=(const ScavTrap &);
		~ScavTrap();
    
		ScavTrap(std::string name);

		void		attack(const std::string& target);
		void		guardGate();
		void		total(void);
};

#endif