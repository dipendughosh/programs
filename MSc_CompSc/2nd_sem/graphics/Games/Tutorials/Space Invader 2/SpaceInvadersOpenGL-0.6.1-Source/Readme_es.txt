
  Space Invaders OpenGL 0.6.1                                   Mayo 2004
  �����������������������������������������������������������������������
 
  Traducci�n (ingl�s a espa�ol)
  �����������������������������������������������������������������������
  El presente documento, y juego, ha sigo traducido del ingl�s al espa�ol
  por
         Autor:      Antonio Caballero Mart�nez
         E-mail:     <war3d@ono.com>
         P�gina Web: La Panocha Digital - The Digital CornCob
                     (http://www.panochadigital.f2o.org/)
                     GnuWin, Open Your Windows (http://gnuwin.epfl.ch/)

  ACERCA DE
  �����������������������������������������������������������������������
  Space Invaders OpenGL es un clon del Space Invaders (un juego arcade
  cl�sico de comienzo de los 80�s), desarrollando con el API del OpenGL.
  El prop�sito es realizar un juego similar en aspecto al original pero
  con mejoras y efectos 2D / 3D.

  Librer�as/fuentes adicionales usadas para el juego:
            - Nehe Basecode (http://nehe.gamedev.net)
            - FMOD Sound System (http://www.fmod.org)
            - GLTexFont (http://nate.scuzzy.net/programming/gltexfont)

  Sonidos:  - 1 000 000 miles by ronny / teklords (Game)
            - StrangleHold (C)JT (About)
            - Digitally Imported http://www.di.fm (Streaming)
  
  Nota: cuando se selecciona una emisora on-line se env�a una petici�n
  a www.google.com para lanzar la conexi�n a Internet y/o configuraci�n
  de cortafuegos.

  REQUIREMENTOS DEL SISTEMA
  �����������������������������������������������������������������������
  - Windows 98/ME/2000/XP
  - Tarjeta gr�fica compatible con OpenGL (Nvidia GeForce, Ati Radeon...)

  TECLAS
  �����������������������������������������������������������������������
  Flecha Arriba,Ctrl -  Disparo
  Left Arrow         -  Desplazar a la izquierda
  Right Arrow        -  Desplazar a la derecha
  Mouse              -  Rotaci�n de la escena
  NumPad +           -  Zoom In
  NumPad -           -  Zoom Out
  B                  -  Cambiar fondo
  M                  -  Sonido Si/No
  R                  -  Redimensionar ventana
  A                  -  Anti-aliasing Si/No (principalmente en modo 3D)
  <F5>+<F6>          -  Trucos
  Escape             -  Salir
  
  FORO
  �����������������������������������������������������������������������
  Si tiene un problema, deje un mensaje en el foro (en ingl�s):
  https://sourceforge.net/forum/?group_id=74529

             Autor:       Mathieu Vidalinc (english/french)
             E-mail:      <maya75@users.sourceforge.net>
             Forum:       https://sourceforge.net/forum/?group_id=74529
             P�gina Web:  http://spaceinvadersgl.sourceforge.net

  VERSION HISTORY
  �����������������������������������������������������������������������
  Mayo  2004 v0.6.1 - Se a�ade soporte para personalizar la URL de la
                      emisora (Lista reproducci�n (*.pls), emisora o
					  archivos mp3.
                      Aparece ahora el nombre del artista y la canci�n.
                    - Se a�aden opciones de comienzo en el registro.
                    - Se a�ade soporte para los teclados virtuales Wivik.
                    - Se a�ade soporte para los gr�ficos PNG usando
                      componentes alfa de textura (transl�cido,
                      antialiasing y sombras). Texturas actualizadas/
                      a�adidas : ecualizador, frames, energ�a.
  
  Enero 2004 v0.6.0 - Se a�ade un vector (Compiled Vertex Array) especial
                      para los objetos 3D dibujados muchas veces (como
                      las naves). Estos objetos se cargan en la memoria
                      GPU para un renderizado m�s r�pido.
                      Necesita una tarjeta gr�fica compatible (todas las
                      �ltimas).
                    - Corregido un bug al entrar en el modo 3D.
                    - Ahora se cargan los modelos 3D desde la memoria
                      interna.
  
  Diciembre 2003 v0.5.9 - Se mejora el modo 3D lineal (se eliminan los
                      artefactos)
                    - Se a�ade la opci�n de Anti-aliasing (principalmente
                      modelos de llenado 3D)
                    - Se corrige finalmente el bug del cambio de m�sica
                      (variable externa)
                    - Se improvisa un ecualizador, y explosiones.
                    - Se a�aden bonus en el modo 3D (mini naves,
                      armamentos)
                    - Se decrementa el tama�o del ejecutable.
                    - Las naves en el modo 3D tienen ahora "puntos de vida".

  Septiembre 2003 v0.5.8 - Se reduce el tama�o del ejecutable.
             v0.5.7 - Algunas peque�as mejoras en el c�digo.
             v0.5.6 - Se mejora la lectura de archivos musicales mp3
                      leyendo los archivos en segundo plano sin que afecte
                      al frame-rate (uso de la nueva bandera FSOUND_
                      NONBLOCKING)
                    - Se a�ade la funcionalidad del ancho de banda de
                      Internet musical.
                    - Se a�ade el ecualizador de espectros.
             v0.5.5 - Corregido un bug mientras se reproduc�an archivos
                      mp3 ("cierre" de la lista)
                    - Se mejora manualmente el mapeo (mipmapping).
                    - Se mejoran los niveles, disparos, y el c�digo fuente.
                    - Se a�ade scroll a los t�tulos de los mp3.
  
  Agosto 2003 v0.5.4 - Se corrige un bug en el que el archivo "msvcr70.dll"
                      falta (fase de linkeo)
                    - Se deshabilita la sincronizaci�n vertical, ahora
                      funciona incluso si est� activado
                      por defecto en las propiedades de pantalla.
                    - Se mejora la carga de los procesos sin hacer uso de
                      las propiedades de thread.
                    - Se a�ade una consola de Debug (� key). Necesita una
                      resoluci�n de 1024x768.
                    - Se a�ade un "viewport" (mini-ventana) en la consola
                      de Debug.
                    - Se a�ade el modo lineal (juego 3D).
                    - Se a�ade la tecla <ctrl> para disparar.
                    - Se a�ade la actualizaci�n del record "Hiscore"
                      mientras se juega.
  
  Agosto 2003 v0.5.3 - Nueva pantalla de inicio con nuevas opciones: VSYNC,
                      billboarding, sombras suaves.
                    - Se a�ade Error de Handle.
                    - Se a�ade la funci�n de sincronizaci�n Vertical.
                    - Se a�ade un an�lisis espectral para la detecci�n de
                      choques.
                    - Se a�ade la ruta de la c�mara (curvas de B�zier)
  
  Julio 2003 v0.5.1 - Se a�ade billboarding para el sistema de part�culas
                      (explosiones, disparos) es decir: estos sprites
                      parecen ahora ser en 3D.
                    - Se a�ade una opci�n de velocidad de carga que hace
                      que la prioridad de carga de los thread sean mayores
                      (aproximadamente el doble de r�pido)
                    - Se a�aden utilidades multil�neas en la ventana de
                      inicio.
                    - Se a�ade la barra de progreso durante la carga.
                    - Se a�ade la rutina de chequeo de versi�n de los fmod
                      por reemplazo.

  Junio 2003 v0.5.0 - Se a�ade multiproceso para la carga en distintos
                      procesos (thread), los cuales refrescan la ventana
                      y permiten moverla/ cerrarla cambiando la prioridad
                      al m�nimo, y entonces volver a normal.
                    - Se a�ade la ventana "Acerca de ..." (dise�o/l�ame/
                      m�sica).
  
  Mayo  2003 v0.4.9 - Se a�ade el modo 3D al juego. 3DS sistema de objetos/
                      particulas disparos/luces/reactores de las naves/etc.
                    - Se mejora la pantalla de inicio: habilitada/
                      deshabilitada botones radio, bot�n mipmap. ventana
                      centrada en el modo ventana.
                    - Se a�ade un pasaje animado al modo 3D con una
                      venatana movida y un anillo a la nave.

  Marzo 2003 v0.4.0 - Se reducen los archivos del juego a un �nico
                      ejecutable.
                    - Se integran los ficheros en los recursos internos:
                      texturas, sonidos y m�sica. fmod.dll es colocada
                      en el directorio /system32 como una librer�a si no
                      existe (y cargada en tiempo de ejecuci�n, no en
                      tiempo de carga).
                    - Se extrae la textura de las fuentes en el directorio
                      temporal de los usuarios y se borra el archivo
                      cuando el usuario sale del juego.
                    - Se utiliza UPX (Ultimate Packer for eXecutable,
                      compresor para ejecutables) para reducir el tama�o
                      del ejecutable.
                    - Se a�ade un modo de pantalla completa r�pido para
                      ejecutar el juego sin tener que cambiar la resoluci�n.
                    - Se a�ade la ventana de carga.
                    - Se a�ade el sistema de part�culas para los efectos
                      de explosiones.
                    - Se implementa la regulaci�n de la inercia
                      independiente del sistema.
                    - Reorganizaci�n de las funciones entre bastantes
                      archivos de c�digo fuente
                      haci�ndolos m�s comprensibles y clarificadores.
                    - Configuraci�n de par�metros y optimizaci�n del debug
                      y los modos de realizaci�n VC++.
                    - Se a�ade fmodvc.lib en el archivo fuente por lo que
                      cualquiera puede compilarlo sin tener que bajarse
                      librer�as adicionales (tambi�n se incluye
                      glTexFont.lib).
                    - Se mejora el gestor de la m�sica: la lectura de los
                      archivos MP3
                      si est�n presentes en el directorio del juego y en
                      cualquier otro caso se lee y reproduce el fichero
                      por defectoe XM.
                    - La imagen de fondo cambia confirme se avanzan en los
                      diferentes niveles.
                    - Se mezclan los archivos de sonido (resampling),
                      decremento del tama�o del ejecutable.
                    - Ahora el record (Hiscore) se almacena en el
                      registro de window.
  
  Marzo 2003 v0.3.1 - Corregido un bug de pantalla (glDepthMask() se
                      requiere la funci�n glDepthMask())
  
  Febrero 2003 v0.3.0 - El c�digo se ha escrito completamente en win32 por
                      lo que el juego se puede ejecutar sin glut. Se
                      corrige el problema del retraso en la latencia con
                      el teclado y se mejora la eficiencia con windows.
                    - Se a�ade un men� al juego en el inicio para escoger
                      la resoluci�n de pantalla, la profundidad del color
                      y el modo a pantalla completa.
                    - Se almacena el record de puntuaci�n de un juego para
                      el siguiente.
  
  Enero 2003 v0.2.0 - Se a�ade un asistente en la instalaci�n para copiar
                      glut32.dll en la carpeta de sistema de windows.
                    - Se a�ade un acceso directo en el men� inicio,
                      posibilitando la desinstalaci�n desde la carpeta de
                      instalaci�n, el men� inicio o el panel de control
                      usando grabaciones en el registro.
  
  Abril 2002 v0.1.0 - La primera versi�n del juego ve la luz.

  LICENCIA
  �����������������������������������������������������������������������
  La Licencia P�blica General GNU (GPL)
	
  Este programa es software gratuito; puede redistribuirlo y/o modificarlo
  bajo los t�rminos de la Licencia P�blica General GNU (GPL) publicada por
  la Free Software Foundation; desde la versi�n 2 de la Licencia, o (en
  su opci�n) a una versi�n posterior.
 
  Este programa se distribuye con el prop�sito de ser util, pero
  SIN NINGUNA GARANT�A; sin incluso la implicaci�n de MERCANTIBILIDAD o
  PROP�SITOS COMERCIALES PERSONALES. Vea la Licencia P�blica General GNU
  (GPL) para m�s detalles.
 
  Debe haber recibido una copia de la Licencia P�blica General GNU (GPL)
  con el programa; si no, escriba a Free Software Foundation, Inc.,
  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA. Para completar
  los t�rminos de la licencia, visite por favor
  http://es.gnu.org/Licencias/fdles.html

  �����������������������������������������������������������������������
                                                         Mathieu Vidalinc


                                          ***********                    
                                    ***********************              
                                 *****************************           
                               *********************************         
                              ************************************       
                             **************************************      
                            *****************************************    
                           ******************************************    
                          ********************************************   
                         **********************************************  
                        ************************************************ 
                       ************************************************* 
                    *****************************************************
                   ****************************************** ***    ****
                  *************************************  **              
                 **************************************    *             
                 ***************************************                 
                 ***************************************                 
***              **************************************                  
*******          ************************************                    
************     ***********************************                     
*****************************************************                    
******************************************************                   
******************************************************                   
*******************************************************    *****         
******************************************************  ********         
*****************************************************   *********        
*****************************************************  ******   *        
****************************************************                     
****************************************************                     
***************************************************                      
***************************************************                      
**************************************************                       
*************************************************                        
*******************************************                              
******************************************  *                            
********************************************          *                  
************************************** *      **     *                   
***************************************            ***                   
************************************             ****                    
**********************************   *        ******                     
***********************************        *********                     
*****************************************************                    
******************************************************                   
*******************************************************                  
*********************************************************                
**********************************************************             