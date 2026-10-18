# MET Weather – STATUS

Oppdatert: 2026-10-18

## Prosjekt

- GitHub: https://github.com/Roysen66/met-weather-opencpn
- Plattform under utvikling: Linux Mint / OpenCPN Flatpak
- Testet OpenCPN-versjon: 5.14.2
- Pluginversjon: 0.1.0.0
- OpenCPN plugin-API: 1.21
- Grunnlag: Testplugin fra OpenCPN
- Eksisterende Testplugin beholdes som separat utvidelse.

## Bekreftet fungerende

- Selvstendig MET Weather-identitet og pluginbibliotek.
- Flatpak-kompilering med SDK 25.08.
- Generering av installasjonspakke med metadata.xml.
- Import via OpenCPNs grafiske utvidelsesbehandling.
- MET Weather og Testplugin installert samtidig.
- MET Weather aktivert uten ikonfeil.
- MET Weather-ikon synlig i utvidelseslisten og verktøylinjen.
- Klikk på MET Weather åpner den eksisterende testdialogen.

## Løst problem: SVG-ikoner

Tidligere brukte tpicons.cpp hardkodede Flatpak-stier.
Dette fungerte ikke med den brukerimporterte utvidelsen.

Løsningen er OpenCPNs offisielle API:

    GetPluginDataDir("metweather_pi")

Funksjonen er dokumentert i opencpn-libs/api-21/ocpn_plugin.h.
Koden legger deretter til undermappen data.

Alle tre SVG-ikonene lastes nå uten den tidligere ikonfeilen.
Dette er bekreftet ved aktivering i OpenCPN.

## Siste bekreftede kildekodeendring

Commit: 030285d
Use OpenCPN API to locate MET Weather icons

Endringen er pushet til GitHub.
Flatpak-bygget og installasjonspakken ble deretter generert
og testet med vellykket resultat.

## Ikke implementert ennå

- MET-værdata og nedlasting.
- Automatisk områdevalg fra fartøyets posisjon.
- Valg mellom Weather, Current og Waves.
- Visning av værdata på kartet.
- Forbedret visualisering og fargeforklaring.
- Tilpasning til nettbrett.
- Eget MET Weather-dialogvindu.

## Viktig avgrensning

Pluginen fungerer teknisk i OpenCPN, men er ennå ikke
en fungerende værutvidelse. Dialogen viser fortsatt
TESTPLUGIN og ODAPI-testinformasjon.

## Arbeidsmetode

- Ett kontrollert steg om gangen.
- Skille mellom kildekode, kompilering, pakking,
  installasjon, aktivering og funksjonstest.
- Oppdatere STATUS.md og NEXT.md ved milepæler.
- Commit og push til GitHub ved viktige milepæler.
- Ikke endre eller fjerne eksisterende Testplugin.
