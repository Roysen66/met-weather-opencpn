# MET Weather – STATUS

Oppdatert: 2026-10-18

## Prosjekt

- GitHub: https://github.com/Roysen66/met-weather-opencpn
- Plattform under utvikling: Linux Mint / OpenCPN Flatpak
- Testet OpenCPN-versjon: 5.14.2
- Pluginversjon: 0.1.0.0
- OpenCPN plugin-API: 1.21
- Flatpak SDK: 25.08
- Grunnlag: Testplugin fra OpenCPN
- Eksisterende Testplugin beholdes som separat utvidelse.

## Bekreftet fungerende

- Selvstendig MET Weather-identitet og pluginbibliotek.
- Flatpak-kompilering og generering av installasjonspakke.
- MET Weather og Testplugin installert samtidig.
- MET Weather-ikoner lastes og vises korrekt.
- Eget MET Weather-dialogvindu.
- Tre knapper: Weather, Current og Waves.
- Foreløpig melding: Weather data not connected yet.
- Dialogen åpnes og lukkes fra verktøylinjen.
- Lukking med X tilbakestiller verktøyknappens tilstand.
- Begge lukkemetodene fungerer likt.
- Dialogen åpnes igjen ved første klikk etter lukking.

## SVG-ikoner

Ikonene lokaliseres gjennom OpenCPNs API:

    GetPluginDataDir("metweather_pi")

Dette erstatter tidligere hardkodede Flatpak-stier.

## Siste bekreftede kildekodeendring

Commit: 1abf702
Synchronize MET Weather dialog close with toolbar state

Endringen er pushet til GitHub.

Flatpak-bygget og installasjonspakken ble generert.
Det installerte pluginbiblioteket har identisk SHA-256
med biblioteket i byggemappen.

Dialogens lukkefunksjon er testet og bekreftet
fungerende i OpenCPN.

## Siste utviklingsarbeid – 18. oktober 2026

Siste commit på GitHub før dagens lokale endringer:

13f3868 – Disable legacy Testplugin message handling

Følgende endringer er gjennomført lokalt:

- Fjernet opprettelse og opprydding av den gamle Testplugin-dialogen.
- Fjernet SaveConfig() og LoadConfig() med tilhørende deklarasjoner.
- Fjernet opprettelse av det gamle tpJSON-objektet.
- Begrenset pluginens forespurte funksjoner til verktøylinje og tilhørende callback.
- Initialisert MET Weather-dialogpekeren i konstruktøren.
- Endret oppryddingen av MET Weather-dialogen til eksplisitt sletting etter at lukkecallbacken er fjernet.
- Lagt til opprydding av ikonobjektet i destruktøren.

Kontroll:

- git diff --check: godkjent.
- Flatpak-kompilering: vellykket.
- Ny installasjonspakke: ikke generert etter disse endringene.
- Import i OpenCPN: ikke testet etter disse endringene.
- Funksjonstest i OpenCPN: ikke utført etter disse endringene.

Endringene er ennå ikke committet eller pushet til GitHub.

Det gjenstår eldre Testplugin-kode som ikke er fjernet.

## Uavklart problem

OpenCPN krasjet to ganger under import av pluginpakker 18. oktober 2026.

En kjernedump bekreftet SIGSEGV. Årsaken er ikke fastslått.

Etter omstart lastet OpenCPN MET Weather uten rapportert
kompatibilitetsfeil, og funksjonstesten var vellykket.

Loggen viste også tidligere meldingen:
"trying to Uninstall non-existing plugin MET Weather"

Sammenhengen med krasjet er ikke bekreftet.

## Ikke implementert ennå

- Tilkobling til MET-værdata.
- Automatisk områdevalg fra fartøyets posisjon.
- Faktisk nedlasting av Weather, Current og Waves.
- Visning av værdata på kartet.
- Forbedret visualisering og fargeforklaring.
- Tilpasning og testing på nettbrett.
- Opprydding i gjenværende eldre Testplugin-kode.

## Viktig avgrensning

MET Weather har nå et eget fungerende brukergrensesnitt,
men er ennå ikke en fungerende værutvidelse.

Knappene er foreløpig plassholdere uten værdatatilkobling.

## Arbeidsmetode

- Ett kontrollert steg om gangen.
- Skille mellom kildekode, kompilering, pakking,
  installasjon, aktivering og funksjonstest.
- Oppdatere STATUS.md og NEXT.md ved milepæler.
- Commit og push til GitHub ved viktige milepæler.
- Ikke endre eller fjerne eksisterende Testplugin.
