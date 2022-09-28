/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:12:38 by hvayon            #+#    #+#             */
/*   Updated: 2022/09/28 20:10:04 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::string s1 = "warrior1";
    std::string s2 = "warrior2";

    ClapTrap    c1(s1);
    ClapTrap    c2(s2);

    c1.attack(s2);
    c2.takeDamage(5);
    c1.total();
    c2.total();

    c1.setAttackDamage(2);
    c2.setAttackDamage(3);
    c1.attack(s2);
    c1.takeDamage(c1.getAttackDamage());
    c2.attack(s2);
    c2.takeDamage(c2.getAttackDamage());
    c1.total();
    c2.total();

    c1.setAttackDamage(10);
    c2.takeDamage(c1.getAttackDamage());
    c2.attack(s2);
    c1.total();
    c2.total();

    c1.beRepaired(2);
    c1.total();
    c2.total();
}