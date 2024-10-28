/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:11:47 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 11:19:01 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_file(int error_code)
{
	if (error_code == 1)
		return (ft_putendl_fd(ERR_MIS_FILE, 2), 1);
	if (error_code == 2)
		return (ft_putendl_fd(ERR_EXT, 2), 1);
	if (error_code == 3)
		return (ft_putendl_fd(ERR_DIR, 2), 1);
	if (error_code == 4)
		return (ft_putendl_fd(ERR_READ, 2), 1);
	return (0);
}

int	error_elements(int error_code)
{
	if (error_code == 0)
		return (ft_putendl_fd(ERR_EMPTY_FILE, 2), 1);
	if (error_code == 1)
		return (ft_putendl_fd(ERR_MIS_TEXT, 2), 1);
	if (error_code == 2)
		return (ft_putendl_fd(ERR_MIS_FC, 2), 1);
	if (error_code == 3)
		return (ft_putendl_fd(ERR_TWICE_TX, 2), 1);
	if (error_code == 4)
		return (ft_putendl_fd(ERR_TX_PATH, 2), 1);
	if (error_code == 5)
		return (ft_putendl_fd(ERR_FC_SYNTAX, 2), 1);
	if (error_code == 6)
		return (ft_putendl_fd(ERR_FC_NUM, 2), 1);
	if (error_code == 7)
		return (ft_putendl_fd(ERR_TWICE_COL, 2), 1);
	return (0);
}

int	error_map(int error_code)
{
	if (error_code == 1)
		return (ft_putendl_fd(ERR_MAP_EL, 2), 0);
	if (error_code == 2)
		return (ft_putendl_fd(ERR_MAP_INVALID_CH, 2), 0);
	if (error_code == 3)
		return (ft_putendl_fd(ERR_MAP_PLAYER, 2), 0);
	if (error_code == 4)
		return (ft_putendl_fd(ERR_MAP_OPEN, 2), 0);
	if (error_code == 5)
		return (ft_putendl_fd(ERR_MAP_SPACE, 2), 0);
	if (error_code == 6)
		return (ft_putendl_fd(ERR_NO_MAP, 2), 0);
	if (error_code == 7)
		return (ft_putendl_fd(ERR_CONFIG, 2), 0);
	return (0);
}
