/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:23 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/07 21:21:31 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read , malloc, free kullanabilirsin
//fd nin işaret ettiği metin dosyasının her seferinde sadece tek satır okuyacak 


#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char		*str;
	static char	*new_str;

	// if (fd < 0 || BUFFER_SIZE <= 0)
	//	return (0);
	new_str = read_line(fd, new_str); //dosyada okuma yapar buffer size kadar okur \n görene kadar dögüde okur .okunan değeri atar
	if (!new_str)
		return (NULL);
	str = getstr(new_str);  //new_str içindeki veriden bir satırı alır ve str ye atar
	new_str = newstr(new_str);  //işlenmiş veriyi (str içindeki satrırı çıkartır) geriye kalanı newstrye atar
	return (str);
}





char main(){

	
}
