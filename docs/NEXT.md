# MET Weather – NEXT

Oppdatert: 2026-10-18

## Nåværende milepæl

MET Weather 0.1.0.0 er kompilert, pakket, importert,
aktivert og testet i OpenCPN 5.14.2 Flatpak.

Neste fase er å erstatte testgrensesnittet med
MET Weathers eget grensesnitt.

## Neste arbeidsoppgaver

1. Lagre oppdaterte STATUS.md og NEXT.md i GitHub.
2. Undersøke eksisterende testdialog og tilhørende kode.
3. Planlegge et minimalt MET Weather-vindu.
4. Erstatte TESTPLUGIN-overskrift og ODAPI-testinformasjon
   med et enkelt MET Weather-grensesnitt.
5. Bygge, pakke, importere og teste endringen i OpenCPN.
6. Dokumentere resultatet og pushe neste milepæl.

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
- Ikke anta at en vellykket kompilering betyr fungerende plugin.
- Test alltid i faktisk OpenCPN etter import.
- Behold eksisterende Testplugin uendret.
- Gjør små, etterprøvbare endringer.

## Viktig

Værfunksjoner er foreløpig planer, ikke implementerte funksjoner.
Ikke start større ombygging før eksisterende dialogkode er undersøkt.
