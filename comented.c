/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comented.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:30:20 by simon2314         #+#    #+#             */
/*   Updated: 2025/12/29 16:30:20 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_higher(char *value, char *limit);

int	rt_parse_util_is_in_range(char *value, char *min, char *max)
{
    int	value_len;
    int	min_len;
    int	max_len;

    value_len = ft_strlen(value);
    min_len = ft_strlen(min);
    max_len = ft_strlen(max);
    if (value_len < min_len && value_len < max_len) // Renvoie 1 même si value est plus courte que max mais peut être < min; logique d’inclusion/exclusion floue.
        return (1);
    if (value_len > min_len || value_len > max_len) // Compare les longueurs pour décider de l’ordre numérique; échoue pour "10" vs "2" (longueur ne reflète pas la valeur).
        return (0);
    if (is_higher(value, max)) // is_higher retourne aussi 1 quand value == max, rejetant la borne max.
        return (0);
    if (is_higher(min, value)) // is_higher(min, value) renvoie 1 quand value == min, rendant l’inclusion de la borne min incohérente.
        return (1);
    return (0);
}

int	is_higher(char *value, char *limit)
{
    if (*value == '-' && *limit == '-')
    {
        limit++;
        value++; // Avance les deux pointeurs d’un caractère sans vérifier la longueur ni normaliser, ce qui peut décaler la comparaison des magnitudes négatives.
    }
    else if (*value != '-' && *limit == '-') // Suppose que tout nombre positif est supérieur à un négatif, sans gérer la chaîne vide ou des signes multiples.
        return (1);
    else if (*value == '-' && *limit != '-') // Suppose tout négatif inférieur, même si les chaînes sont invalides.
        return (0);
    while (*value && *limit)
    {
        if (*limit == '.' && *value && *value != '.') // Traite un point dans limit comme plus petit qu’un chiffre dans value, ce qui inverse l’ordre pour "12.9" vs "12.10".
            return (1);
        if (*value == '.' && *limit && *limit != '.') // Symétrique: traite un point dans value comme plus petit qu’un chiffre dans limit; ordre incorrect sur décimales.
        if (*value > *limit) // Comparaison lexicographique brute: "2" > "10" devient vrai caractère par caractère; ignore la valeur numérique.
            return (1);
        value++;
        if (*value == '\0') // Si value termine plus tôt, retourne 0, donc "12" est considéré inférieur à "12.0" ou "12x" sans valider les caractères restants.
            return (0);
        limit++;
    }
    return (1); // Retourne 1 quand les deux chaînes se terminent simultanément ou limit finit avant, traitant l’égalité comme "value plus grand".
}
