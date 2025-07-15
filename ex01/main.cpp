/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:35:02 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/09 16:50:39 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data*	data = new Data;
	data->name = "Test";
	data->value = 42;

	std::cout	<< "Original Data: Name = " << data->name
				<< "\n               Value = "
				<< data->value << std::endl;
	std::cout << "Original Pointer: " << data << std::endl;

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	Data*	deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Pointer: " << deserialized << std::endl;
	std::cout	<< "Deserialized Data: Name = " << deserialized->name
				<< "\n                   Value = "
				<< deserialized->value << std::endl;
	
	if (data == deserialized)
		std::cout << "Success: Original and deserialized pointers match!" << std::endl;
	else
		std::cout << "Error: Pointers do not match!" << std::endl;
	
	delete data;
	return (0);
}