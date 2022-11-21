/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:23:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/05 02:30:38 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long/inc/so_long.h"
#include "../unity/src/unity.h"

void test_elements(void)
{
	t_data	data1;
	t_data	data2;
	t_data	data3;
	t_data	data4;
	t_data	data5;
	t_data	data6;

	data1.map = read_map_file("../so_long/map/map1.ber");
	data2.map = read_map_file("../so_long/map/map2.ber");
	data3.map = read_map_file("./map/two_exit.ber");
	data4.map = read_map_file("./map/two_starting_point.ber");
	//data5.map = read_map_file("./map/empytmap.ber");
	data5.map = read_map_file("./map/no_collectibles.ber");
	data6.map = read_map_file("./map/no_start.ber");


	init_data(&data1);
	init_data(&data2);
	init_data(&data3);
	init_data(&data4);
	init_data(&data5);
	init_data(&data6);

	TEST_ASSERT_EQUAL(1, ck_elements(data1));
	TEST_ASSERT_EQUAL(1, ck_elements(data2));
	TEST_ASSERT_EQUAL(0, ck_elements(data3));
	TEST_ASSERT_EQUAL(0, ck_elements(data4));
	TEST_ASSERT_EQUAL(0, ck_elements(data5));
	TEST_ASSERT_EQUAL(0, ck_elements(data6));
}
