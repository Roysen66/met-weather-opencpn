# MET Weather – NEXT

Oppdatert: 2026-10-18

## Nåværende milepæl

MET Weather 0.1.0.0 har et eget dialogvindu med
Weather, Current og Waves.

Åpning og lukking fra verktøylinjen fungerer.
Lukking med X fungerer og tilbakestiller verktøyknappen.

Funksjonene er bekreftet i OpenCPN 5.14.2 Flatpak.

Værdata er ennå ikke tilkoblet.

## Neste arbeidsoppgaver

1. Fullføre oppdateringen av STATUS.md og NEXT.md.
2. Kontrollere dokumentendringene med `git diff --check`
   og `git diff`.
3. Committe og pushe dokumentasjonen til GitHub.
4. Kontrollere at dialogen fortsatt åpnes og lukkes
   korrekt etter siste livssyklusendring.
5. Beholde midlertidige debugmeldinger inntil
   pluginens stabilitet er tilstrekkelig bekreftet.
6. Gjennomgå gjenværende eldre Testplugin-kode
   og vurdere hva som faktisk kan fjernes.
7. Undersøke MET Norges datakilder for
   Weather, Current og Waves.
8. Avklare dataformater, geografisk dekning
   og oppdateringsintervaller.
9. Planlegge første datatilkobling med automatisk
   områdevalg basert på fartøyets posisjon.
10. Implementere og teste datatilkoblingen
    i små, kontrollerte steg.

Ikke endre den separat installerte Testplugin.

Skille mellom kompilering, pakking, import,
aktivering og funksjonstest.

## Tidligere krasj – videre oppfølging

OpenCPN krasjet flere ganger under import av
MET Weather-pluginpakker 18. oktober 2026.

Kjernedump bekreftet SIGSEGV.

Krasjstakken viste blant annet:
- OpenCPN `ConnectionsDlg::OnResize()`
- wxWidgets `wxWindowBase::FindWindowByName()`

Den underliggende årsaken er fortsatt ukjent.

### Siste bekreftede tester

Med commit `6e1f463` er følgende gjennomført:

- Flatpak-bygging og pakking uten feil.
- Alle seks debugmeldinger bekreftet i biblioteket.
- Import i OpenCPN uten krasj.
- Normal avslutning av OpenCPN.
- Komplett livssyklus bekreftet i loggen.
- Ny import over eksisterende plugin uten krasj.
- Korrekt avslutning og ny initialisering bekreftet.

### Videre håndtering

- Behold de midlertidige debugmeldingene.
- Følg med på eventuelle nye krasj.
- Undersøk nye krasjlogger dersom problemet kommer tilbake.
- Ikke anta at endringen i `DeInit()` var årsaken
  til at krasjene opphørte.

**Status: Ingen krasj i siste tester.
Opprinnelig årsak er ikke fastslått.**

## Videre utviklingsmål

### Brukeropplevelse

- Automatisk geografisk område basert på aktuell posisjon.
- Enkelt valg mellom Weather, Current og Waves.
- Færrest mulig dialoger og manuelle valg.
- Ingen krav om å holde et stort GRIB-vindu åpent.
- God betjening på både PC og nettbrett.

### Værdata

- Undersøke MET Norges relevante datakilder og API-er.
- Avklare dataformater, dekning og oppdateringsintervaller.
- Implementere nedlasting og lokal håndtering av data.
- Skille tydelig mellom vær, strøm og bølger.

### Kartvisning

- Tydelig og lesbar presentasjon i OpenCPN.
- Forklaring av farger, enheter og symboler.
- Kontroll over gjennomsiktighet.
- Unngå at værgrafikken skjuler viktig kartinformasjon.

## Tekniske prinsipper

- Bruk OpenCPNs API fremfor hardkodede installasjonsstier.
- Behold kompatibilitet med OpenCPNs plugin-system.
- Ikke anta at vellykket kompilering betyr fungerende plugin.
- Test funksjoner i faktisk OpenCPN.
- Behold eksisterende separate Testplugin uendret.
- Gjør små, etterprøvbare endringer.
- Dokumenter bekreftede resultater og uavklarte feil.
- Ett kontrollert steg om gangen.

## Viktig

MET Weather har et fungerende grunnleggende brukergrensesnitt,
men er ennå ikke en fungerende værutvidelse.

Weather, Current og Waves er foreløpig plassholdere.
