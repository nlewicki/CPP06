/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:02:01 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/14 12:11:31 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
