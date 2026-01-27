/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:07:36 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 16:04:16 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_USAGE "usage ./miniRT <scene.rt>"
#define ERROR_SYSTEM "Failure system"
#define ERROR_IDENTIFIER "Wrong identifier"
#define ERROR_REAL_NB_FORMAT "incorrect format of nb"
#define ERROR_OUT_OF_RANGE "An argument is out of range"
#define ERROR_ARG_QUANTITY "wrong quantity of argument on a line"
#define ERROR_VECTOR "A vector is not correct"

void	rt_error_put(char *message);

#endif
