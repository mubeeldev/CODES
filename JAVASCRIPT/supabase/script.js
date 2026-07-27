// script.js
// Import the Supabase client library from the CDN
import { createClient } from 'https://cdn.jsdelivr.net/npm/@supabase/supabase-js@2/dist/module/supabase.js';

const supabaseUrl = 'https://tbevljdwmtabqbaontsc.supabase.co';
const supabaseKey = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InRiZXZsamR3bXRhYnFiYW9udHNjIiwicm9sZSI6ImFub24iLCJpYXQiOjE3ODQ4OTI2NzYsImV4cCI6MjEwMDQ2ODY3Nn0.xeQGGAYEOdU6yUIa9ntFxW68IcH_Vc7StYzp7RVFhFg';

const supabase = createClient(supabaseUrl, supabaseKey);

const messageEl = document.getElementById('message');
const signupForm = document.getElementById('signup-form');

signupForm.addEventListener('submit', async (event) => {
    event.preventDefault();

    const name = signupForm.name.value.trim();

    if (!name) {
        messageEl.textContent = 'Please enter your name.';
        return;
    }

    messageEl.textContent = 'Saving your name...';

    const { data, error } = await supabase.from('signups').insert([{ name }]);

    if (error) {
        messageEl.textContent = `Error: ${error.message}`;
        return;
    }

    messageEl.textContent = 'Signup saved! Thank you.';
    signupForm.reset();
});
