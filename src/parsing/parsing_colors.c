/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:30:45 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 11:20:39 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Function to count the commas : if different than 2,
//	then the syntax is invalid
static int	count_commas(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!line)
		return (0);
	while (line[i] && i < (int)ft_strlen(line))
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

// Function to collect the colors of the F and C
// We perform an atoi on each element of the rgb table,
// verify that the values are correct
// Then we call the conversion to hex function
int	retrieve_colors(char *line, char **rgb, t_data *data)
{
	long	r;
	long	g;
	long	b;
	long	a;

	(void)data;
	r = (long)ft_atoi_cub(rgb[0]);
	g = (long)ft_atoi_cub(rgb[1]);
	b = (long)ft_atoi_cub(rgb[2]);
	if (r == -1 || g == -1 || b == -1)
		return (error_elements(5), 0);
	a = 255;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (error_elements(6), 0);
	if (line[0] == 'F')
		data->collect->color_f = convert_to_hex(r, g, b, a);
	if (line[0] == 'C')
		data->collect->color_c = convert_to_hex(r, g, b, a);
	return (1);
}

static int	colors_c(char *line, t_data *data, int i)
{
	if (data->collect->color_c)
		return (error_elements(7), 0);
	data->collect->c_rgb = ft_split((const char *)line + i, ',');
	if (!data->collect->c_rgb)
		return (error_elements(5), 0);
	if (!retrieve_colors(line, data->collect->c_rgb, data))
		return (0);
	return (1);
}

static int	colors_f(char *line, t_data *data, int i)
{
	if (data->collect->color_f)
		return (error_elements(7), 0);
	data->collect->f_rgb = ft_split((const char *)line + i, ',');
	if (!data->collect->f_rgb)
		return (error_elements(5), 0);
	if (!retrieve_colors(line, data->collect->f_rgb, data))
		return (0);
	return (1);
}

// Function to treat the color fields
int	collect_colors_fc(char *line, t_data *data)
{
	int	i;
	int	c;

	i = ((c = 0));
	while (line[i] && ft_checkspaces(line[i]))
		i++;
	while (line[i] && (line[i] == 'F' || line[i] == 'C') && (line[i + 1]
			&& ft_checkspaces(line[i + 1])))
	{
		if (line[i] == 'F')
			c = 1;
		i += 2;
	}
	while (line[i] && ft_checkspaces(line[i]))
		i++;
	if (!count_commas(line + i))
		return (error_elements(5), 0);
	if (c == 0 && !colors_c(line, data, i))
		return (0);
	if (c == 1 && !colors_f(line, data, i))
		return (0);
	return (1);
}
