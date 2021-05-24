IF NOT EXIST "%ProgramFiles(x86)%\Foxit Software\Foxit PhantomPDF\plugins\PISignatureGen.exe" COPY "%~dp0PISignatureGen.exe" "%ProgramFiles(x86)%\Foxit Software\Foxit PhantomPDF\plugins\PISignatureGen.exe"
REM SET PISignatureGenPath="%~dp0PISignatureGen.exe"
SET PISignatureGenPath="%ProgramFiles(x86)%\Foxit Software\Foxit PhantomPDF\plugins\PISignatureGen.exe"
SET PluginPath="%ProgramFiles(x86)%\Foxit Software\Foxit PhantomPDF\plugins\%1.fpi"
IF NOT "%2"=="" SET PluginPath="%ProgramFiles(x86)%\Foxit Software\Foxit PhantomPDF\plugins\%1 %2.fpi"
IF NOT "%3"=="" SET PluginPath="%ProgramFiles(x86)%\Foxit Software\Foxit PhantomPDF\plugins\%1 %2 %3.fpi"
SET frdpisdkeyPath="%~dp0frdpisdkey.txt"
%PISignatureGenPath% /sign %PluginPath% %frdpisdkeyPath%