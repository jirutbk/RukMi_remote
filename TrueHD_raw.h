// Data captured by IRrecvDumpV2.ino
// True Digital HD2 
uint16_t power[71] = {9032, 4440,  596, 544,  594, 544,  592, 546,  596, 542,  592, 546,  594, 542,  594, 544,  594, 546,  596, 542,  596, 544,  594, 542,  594, 544,  594, 1668,  594, 542,  594, 542,  594, 546,  594, 546,  594, 546,  592, 544,  594, 546,  594, 544,  592, 546,  594, 546,  594, 542,  594, 1666,  594, 1668,  594, 1666,  594, 1668,  590, 1668,  592, 1668,  594, 1666,  594, 1666,  594, 47818,  9030, 2234,  592};  
uint16_t source[71] = {9034, 4444,  594, 542,  594, 546,  594, 544,  596, 544,  594, 544,  594, 544,  596, 544,  594, 544,  594, 546,  594, 542,  596, 544,  594, 546,  594, 1666,  594, 544,  594, 544,  594, 546,  592, 546,  596, 542,  594, 1668,  594, 1666,  592, 1666,  596, 544,  594, 544,  594, 542,  596, 1666,  594, 1664,  594, 544,  594, 544,  594, 544,  594, 1666,  594, 1666,  594, 1668,  594, 47876,  9030, 2234,  594};                       
uint16_t mute[67] = {9032, 4440,  596, 542,  596, 542,  596, 544,  594, 546,  594, 544,  594, 544,  596, 540,  598, 542,  596, 542,  596, 542,  596, 546,  594, 544,  596, 1664,  596, 542,  598, 542,  594, 542,  596, 544,  594, 544,  594, 546,  594, 1666,  594, 1666,  594, 544,  596, 544,  594, 544,  592, 1664,  598, 1664,  596, 1666,  594, 546,  594, 544,  596, 1664,  594, 1666,  594, 1666,  594};
uint16_t soundInc[71] = {9032, 4442,  596, 542,  596, 542,  594, 546,  594, 544,  596, 542,  594, 544,  594, 544,  596, 542,  596, 544,  592, 544,  596, 544,  594, 544,  594, 1664,  594, 544,  594, 544,  596, 542,  594, 1668,  592, 1666,  594, 1666,  594, 1666,  594, 1666,  594, 542,  594, 544,  594, 544,  594, 546,  596, 544,  594, 542,  596, 544,  594, 544,  594, 1668,  592, 1666,  594, 1666,  596, 47856,  9030, 2232,  596};
uint16_t soundDec[67] = {9034, 4442,  592, 544,  594, 546,  592, 546,  594, 544,  594, 546,  594, 544,  596, 542,  594, 544,  594, 544,  594, 544,  594, 544,  596, 544,  594, 1668,  592, 544,  598, 542,  592, 548,  592, 546,  594, 544,  592, 544,  596, 544,  592, 546,  594, 542,  596, 1666,  592, 546,  594, 1668,  592, 1666,  594, 1668,  592, 1668,  594, 1666,  594, 1666,  594, 544,  592, 1670,  594};                   
uint16_t chInc[71] = {9034, 4444,  592, 544,  596, 544,  592, 546,  594, 542,  596, 546,  592, 546,  594, 544,  594, 544,  596, 544,  592, 546,  592, 546,  594, 544,  594, 1666,  592, 546,  594, 544,  594, 542,  596, 546,  594, 544,  594, 546,  594, 542,  596, 1666,  594, 546,  594, 542,  596, 544,  594, 1668,  594, 1666,  596, 1666,  592, 1666,  594, 544,  594, 1666,  594, 1666,  592, 1668,  592, 47878,  9032, 2232,  592}; 
uint16_t chDec[71] = {9032, 4444,  594, 544,  594, 544,  594, 544,  594, 544,  594, 544,  594, 542,  594, 546,  594, 546,  594, 544,  594, 544,  596, 544,  594, 544,  594, 1666,  592, 546,  594, 544,  594, 544,  594, 1668,  594, 1668,  592, 1668,  594, 1664,  594, 544,  594, 546,  592, 544,  596, 544,  594, 544,  594, 544,  594, 546,  594, 546,  594, 1666,  596, 1666,  594, 1666,  592, 1668,  594, 47854,  9030, 2232,  594};
uint16_t binfo[71] = {9028, 4442,  592, 546,  592, 546,  594, 546,  592, 544,  594, 544,  594, 544,  592, 546,  592, 546,  592, 548,  594, 544,  592, 546,  594, 544,  594, 1666,  592, 544,  594, 546,  592, 544,  594, 1668,  594, 1668,  594, 546,  592, 546,  592, 546,  594, 544,  594, 1666,  594, 546,  592, 546,  592, 548,  592, 1668,  594, 1666,  594, 1666,  594, 1666,  594, 544,  594, 1668,  594, 47856,  9032, 2234,  592}; 
uint16_t bexit[71] = {9030, 4444,  594, 544,  594, 544,  594, 544,  592, 548,  594, 546,  590, 546,  594, 546,  594, 544,  594, 544,  596, 544,  592, 546,  594, 542,  594, 1668,  594, 544,  594, 544,  592, 546,  594, 544,  594, 1668,  594, 1668,  592, 546,  592, 1666,  594, 544,  594, 546,  592, 544,  596, 1668,  592, 544,  594, 544,  594, 1668,  594, 542,  596, 1668,  592, 1668,  590, 1668,  594, 47868,  9030, 2232,  592};
                         
uint16_t num[][71] = {{9030, 4446,  594, 544,  592, 546,  594, 544,  594, 546,  594, 544,  592, 546,  596, 544,  594, 546,  594, 544,  594, 546,  592, 544,  592, 546,  592, 1668,  592, 546,  594, 544,  594, 546,  594, 546,  592, 548,  592, 1668,  594, 1668,  590, 546,  594, 544,  594, 544,  592, 546,  594, 1668,  592, 1668,  594, 544,  594, 546,  592, 1668,  594, 1668,  592, 1668,  594, 1670,  592, 47872,  9030, 2234,  592},
                        {9032, 4444,  592, 544,  594, 544,  594, 546,  592, 544,  594, 544,  594, 546,  592, 548,  592, 546,  592, 546,  594, 544,  596, 542,  594, 544,  596, 1666,  596, 544,  594, 544,  594, 544,  598, 1666,  594, 1666,  594, 546,  594, 542,  596, 544,  594, 544,  596, 544,  594, 544,  596, 544,  594, 544,  596, 1666,  594, 1666,  594, 1668,  592, 1668,  592, 1668,  594, 1668,  592, 47872,  9032, 2230,  594},
                        {9030, 4442,  594, 544,  592, 544,  594, 546,  592, 546,  594, 542,  596, 544,  594, 544,  594, 544,  594, 544,  592, 546,  594, 544,  594, 542,  596, 1666,  592, 546,  592, 544,  596, 542,  594, 546,  594, 544,  596, 1664,  596, 542,  596, 544,  596, 542,  594, 544,  594, 544,  596, 1664,  594, 1666,  594, 546,  594, 1666,  594, 1664,  596, 1664,  596, 1664,  592, 1668,  594, 47864,  9032, 2232,  594},
                        {9032, 4442,  592, 544,  594, 544,  594, 546,  592, 548,  590, 546,  594, 544,  594, 546,  592, 546,  594, 544,  596, 544,  594, 546,  594, 544,  594, 1668,  594, 544,  592, 546,  594, 546,  592, 1670,  592, 544,  594, 1668,  594, 544,  594, 546,  592, 544,  592, 546,  592, 546,  594, 544,  594, 1668,  592, 546,  594, 1666,  592, 1670,  592, 1666,  592, 1668,  592, 1670,  594, 0, 0, 0, 0},
                        {9026, 4444,  592, 546,  594, 546,  592, 546,  594, 546,  594, 544,  592, 548,  592, 544,  592, 548,  590, 546,  592, 548,  594, 544,  596, 544,  592, 1668,  594, 546,  594, 542,  594, 546,  594, 546,  594, 1668,  592, 1668,  594, 544,  592, 546,  594, 544,  594, 546,  592, 546,  594, 1668,  590, 546,  594, 546,  592, 1668,  594, 1666,  592, 1668,  590, 1668,  592, 1668,  594, 47834,  9032, 2230,  592},
                        {9030, 4446,  592, 546,  594, 544,  592, 546,  592, 544,  594, 546,  592, 546,  594, 546,  592, 546,  594, 544,  594, 548,  594, 544,  592, 546,  594, 1666,  594, 544,  594, 544,  592, 546,  594, 1668,  594, 1666,  592, 1668,  592, 544,  594, 546,  594, 544,  594, 546,  592, 546,  594, 544,  594, 546,  592, 548,  592, 1668,  592, 1668,  594, 1666,  592, 1668,  594, 1670,  592, 0, 0, 0, 0},
                        {9034, 4444,  592, 544,  594, 544,  592, 546,  594, 546,  592, 546,  594, 546,  592, 544,  596, 544,  592, 548,  592, 546,  594, 544,  592, 546,  594, 1664,  594, 546,  592, 544,  596, 544,  594, 546,  594, 544,  594, 546,  592, 1670,  592, 546,  594, 544,  594, 546,  596, 542,  596, 1666,  594, 1668,  592, 1668,  594, 546,  592, 1668,  592, 1668,  594, 1668,  592, 1668,  592, 0, 0, 0, 0},
                        {9034, 4446,  594, 544,  594, 546,  594, 544,  592, 546,  594, 548,  590, 546,  592, 546,  594, 546,  594, 544,  594, 544,  592, 546,  594, 544,  594, 1668,  592, 546,  594, 544,  594, 546,  592, 1670,  592, 546,  594, 546,  594, 1666,  594, 546,  592, 546,  594, 546,  592, 546,  594, 544,  594, 1670,  590, 1670,  592, 544,  596, 1668,  592, 1668,  592, 1668,  592, 1668,  594, 0, 0, 0, 0},
                        {9032, 4444,  592, 546,  594, 544,  594, 546,  590, 546,  596, 544,  592, 546,  594, 546,  592, 546,  592, 544,  596, 544,  594, 544,  592, 546,  594, 1670,  592, 544,  596, 542,  596, 542,  594, 546,  594, 1668,  594, 542,  594, 1668,  592, 546,  592, 546,  594, 544,  594, 544,  596, 1666,  594, 546,  594, 1668,  592, 544,  592, 1670,  594, 1668,  592, 1668,  592, 1668,  594, 0, 0, 0, 0},
                        {9030, 4446,  592, 544,  592, 546,  592, 548,  594, 544,  594, 544,  592, 546,  592, 546,  594, 546,  592, 546,  594, 546,  594, 544,  592, 546,  592, 1666,  594, 546,  594, 544,  592, 544,  594, 1668,  592, 1670,  592, 544,  594, 1668,  594, 546,  592, 546,  592, 544,  594, 546,  594, 546,  594, 546,  592, 1668,  592, 546,  592, 1666,  594, 1668,  592, 1668,  594, 1668,  594, 47898,  9032, 2234,  592}}; 

