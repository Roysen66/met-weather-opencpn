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

## Siste bekreftede kildekodeendringer

Følgende commits er pushet til GitHub:

- `a574e68` – Remove legacy Testplugin dialog and config handling
- `7f3401d` – Clean up plugin lifecycle and update development status
- `6e1f463` – Add lifecycle debug logging for MET Weather

Siste commit inneholder seks midlertidige debugmeldinger:

- Constructor
- Destructor
- Init START
- Init END
- DeInit START
- DeInit END

Det eksplisitte kallet til `RemovePlugInTool()` er fjernet
fra `DeInit()`.

Flatpak-bygging og pakking er fullført uten feil.
Alle seks debugmeldingene er bekreftet i pluginbiblioteket.

## Siste utviklingsarbeid – 18. oktober 2026

Oppryddingen i pluginens livssyklus er gjennomført
og committet til GitHub.

Gjennomførte endringer:

- Fjernet opprettelse av den gamle Testplugin-dialogen.
- Fjernet SaveConfig() og LoadConfig().
- Fjernet opprettelse av det gamle tpJSON-objektet.
- Begrenset forespurte pluginfunksjoner til verktøylinjen.
- Initialisert MET Weather-dialogpekeren i konstruktøren.
- Fjernet lukkecallback før sletting av dialogen.
- Lagt til opprydding av ikonobjektet i destruktøren.

Kontroll:

- Flatpak-kompilering: vellykket.
- Installasjonspakke: generert.
- Import i OpenCPN: vellykket.
- Normal avslutning: bekreftet.
- Ny import over eksisterende plugin: vellykket.

Det gjenstår eldre Testplugin-kode som skal
vurderes under videre opprydding.

### Videre opprydding – 18. oktober 2026

- Fjernet tre ubrukte timerdeklarasjoner.
- Initialisert `m_testplugin_button_id` til `-1`.
- Fjernet eksplisitt `RemovePlugInTool()` fra `DeInit()`.
- Bekreftet OpenCPN plugin-API 1.21.
- Lagt til seks midlertidige livssykluslogger.
- Kontrollert endringene med `git diff --check`.
- Committet og pushet endringene til GitHub.

Siste commit: `6e1f463`

### Bekreftede tester

- Flatpak-bygging fullført uten feil.
- Installasjonspakke generert.
- Alle seks debugmeldinger finnes i pluginbiblioteket.
- Første import i OpenCPN gjennomført uten krasj.
- OpenCPN avsluttet normalt.
- Ny import over eksisterende plugin gjennomført uten krasj.
- Komplett avslutning og ny initialisering bekreftet
  i OpenCPN-loggen klokken 21:10:50.

Den tidligere krasjårsaken er fortsatt ikke fastslått.

## Tidligere krasj – status

OpenCPN krasjet flere ganger under import av
MET Weather-pluginpakker 18. oktober 2026.

En kjernedump bekreftet SIGSEGV.

Undersøkelsen av krasjstakken viste blant annet:

- OpenCPN `ConnectionsDlg::OnResize()`
- wxWidgets `wxWindowBase::FindWindowByName()`

Den underliggende årsaken er ikke fastslått.

Loggmeldingen
"trying to Uninstall non-existing plugin MET Weather"
har også forekommet ved vellykket import.
Det er ikke påvist at meldingen forårsaket krasjet.

### Tester med siste versjon

Med commit `6e1f463` er følgende bekreftet:

- Import av MET Weather uten krasj.
- Normal avslutning av OpenCPN.
- Komplett livssyklus i debugloggen.
- Ny import over eksisterende plugin uten krasj.
- Korrekt avslutning av gammel plugininstans.
- Korrekt initialisering av ny plugininstans.

Ved ny import klokken 21:10:50 ble den gamle
plugininstansen avsluttet og destruert før den
nye instansen ble opprettet og initialisert.

**Status: Krasjet er ikke gjenskapt med siste
versjon. Den opprinnelige årsaken er fortsatt
uavklart.**

De midlertidige debugmeldingene beholdes
foreløpig for videre diagnostikk.

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
