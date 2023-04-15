if ($args.Length -ne 4)
{
	echo "utilisation: ./check_client_backup.ps1 <ip> <login> <password> <path>"
	echo " ip: ip du serveur de sauvegarde"
	echo " login: le login du compte de connexion"
	echo " password: le mot de passe"
	echo " path: le chemin vers le dossier de sauvegarde du client"
	exit
}

Write-Host "Verification de la sauvegarde du dossier " -NoNewLine
Write-Host $args[3] -NoNewLine -ForegroundColor Blue
Write-Host " sur le serveur " -NoNewLine
Write-Host $args[0] -NoNewLine -ForegroundColor Blue
Write-Host " avec les identifiants " -NoNewLine
Write-Host $args[1] -NoNewLine -ForegroundColor Blue
Write-Host " " -NoNewLine
Write-Host $args[2] -ForegroundColor Blue

$pass = convertto-securestring -AsPlainText -Force -String $args[2]
$cred = new-object -typename System.Management.Automation.PSCredential -argumentlist $args[1],$pass

Invoke-Command -ComputerName $args[0] -Credential $cred -ScriptBlock {
	Get-Date
}
Write-Host $?
# else
# {
# 	Write-Host "Erreur" -ForegroundColor Red
# 	$nb_echecs++
# }

# Write-Host "Script execute sur " -NoNewLine
# Write-Host $nb_succes -NoNewLine -ForegroundColor Green
# Write-Host " serveurs, " -NoNewLine
# Write-Host $nb_echecs -NoNewLine -ForegroundColor Red
# Write-Host " echecs"