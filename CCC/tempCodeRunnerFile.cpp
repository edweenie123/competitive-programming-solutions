for (int j=0;j<3;j++) {
            r[j] = {r[j].f+1, r[j].s+1};
            if (r[j].f>n) r[j].f = r[j].f % n;
            if (r[j].s>n) r[j].s = r[j].s % n;
        }