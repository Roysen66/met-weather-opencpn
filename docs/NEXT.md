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

1. Lagre oppdaterte STATUS.md og NEXT.md i GitHub.
2. Undersøke gjenværende Testplugin-kode inne i MET Weather.
3. Planlegge trygg opprydding uten å endre separat Testplugin.
4. Undersøke MET Norges datakilder for Weather, Current og Waves.
5. Avklare dataformat, geografisk dekning og oppdateringsintervall.
6. Planlegge automatisk områdevalg basert på fartøyets posisjon.
7. Implementere første datatilkobling i små, testbare steg.
8. Bygge, pakke, installere og funksjonsteste hver milepæl.

## Uavklart feil

OpenCPN krasjet under import av MET Weather 18. oktober 2026.

Kjernedump bekreftet SIGSEGV, men årsaken er ikke fastslått.

Den installerte pluginfilen ble kontrollert mot byggefilen
med SHA-256 og var identisk.

Etter omstart fungerte MET Weather.

Undersøk importprosessen videre før feilen regnes som løst.
Unngå å anta at krasjet skyldes den siste kodeendringen.

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
