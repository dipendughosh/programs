dir /a:d /b > list.txt
for /F "tokens=*" %%A in  (list.txt) do  (
   ECHO Processing %%A
   cd %%A
   gradlew.bat clean
   cd ..
)