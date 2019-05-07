# cairadar
Radar screen written on C++ &amp; Cairo

**Current aim:** to make radar screen emulator with live ADS-B data displayed on it.

### Brief description

`C_radar_sweep` — class that implements radar sweep with kilometer lines and kilometer marks.
`C_radar_ray` — class that imlements radar ray. Defines radar width and speed of its rotation.

`cairadar` uses Cairo graphics lib with X11 server backend.

### TODO List

- [x] Radar sweep rendering
- [ ] Rendering rotating radar ray with gradient
- [ ] Airbourne target marks and information rendering
- [ ] Parsing ADS-B data via HTTP request

