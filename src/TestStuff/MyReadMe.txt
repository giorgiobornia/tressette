== Info
In questa directory e sottodirectories sono presenti files per testare
le classi del tressette. Il framework usato è CxxTest.

== Prima di partire
Settare una variabile utente PYTHON con il valore C:\Python23\python.exe, oppure 
con il valore dove si trova python (non usare perl in quanto ho cambiato lo script di python).

== Eseguire i test
Eseguire il "rebuild all" del progetto  .\TestCases\msvc\CxxTest_1_Run.dsp
Nella finestra Build di visual studio 6 compariranno alla fine del build
i risultati del test. 

== CxxTest in Tressette
Per aggiungere CxxTest al proprio progetto
basta copiare tutta la struttura qui presente.
Nel progetto CxxTest_2_Build vi ho messo dentro tutta la mia applicazione da testare 
(vedi includes e linker options).
I test sono nella directory ./TestCases e sono negli header in questa directory. 
Un test è un metodo che comincia con la parola test. 
Ho cambiato il Makefile originale (quello presente della distribuzione cxxTest)
 ed ho tolto la sottodirectory gui. Ho introdotto nel makefile la variabile
DIRRUNNER, in modo che runner sia eseguito nella stessa directory di tre.exe, questo 
per evitare che runner.exe non trovi le dll e risorse da cui dipende.
Il make file viene eseguito con il build del progetto CxxTest_1_Run.dsp.


== Reference
Comparazione di diversi c++ unit test
http://www.gamesfromwithin.com/articles/0412/000061.html#cppunitlite
Cxx home page
http://cxxtest.sourceforge.net/