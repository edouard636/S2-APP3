# Edouard Tremblay      tree1705                                                
# Mathieu Gagnon        gagm2641                                                
# Gabriel Berthiaume    berg2227                                                
# makefile pour l'App 3 POO                                                     
# But :                                                                         
#       Produire le fichier app3                                                
app3: menu.o menufact01.o plats.o test_menu_fact.o                              
        g++ -o app3 menu.o menufact01.o plats.o test_menu_fact.o                
#                                                                               
menu.o: menu.cpp menu.h                                                         
        g++ menu.cpp -g -c                                                      
#                                                                               
menufact01.o: menufact01.cpp facture.h menu.h test_menu_fact.h                  
        g++ menufact01.cpp -g -c                                                
#                                                                               
plats.o: plats.cpp plats.h                                                      
        g++ plats.cpp -g -c                                                     
#                                                                               
test_menu_fact.o: test_menu_fact.cpp test_menu_fact.h menu.h facture.h          
        g++ test_menu_fact.cpp -g -c                                            
#                                                                               
clean:
/dsk/home/tree1705/Bureau/MenuFact01_code/makefile (2/2) 
        rm -f *.o                                                               
#Fin du makefile                                                                
                    
