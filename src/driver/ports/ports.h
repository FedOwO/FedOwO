//
// Created by d_lucas_doo on 14/03/23.
//

#ifndef PORTS_H
    #define PORTS_H

unsigned char port_byte_in (unsigned short port);
unsigned short port_word_in (unsigned short port);
void port_byte_out (unsigned short port, unsigned char data);
void port_word_out (unsigned short port, unsigned short data);

#endif //FEDOWO_PORTS_H
