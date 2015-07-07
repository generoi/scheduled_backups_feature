# Automatic Backup

This feature enables rotated schedueld backups as follows:

- 7 daily backups
- 4 weekly backups
- 12 monthly backups

## Installation

1. Enable the feature on production (not any other environment).
2. Configure Elysia Cron.
3. Make sure there's a private filesystem path configured (and that it in fact is private).
4. Add any additional database exclusions (eg. custom caches, migrate tables) for the `General Backup` profile at /admin/config/system/backup_migrate/settings/profile/edit/general_backup

### Add a cron task

We want to fetch the new backups from each remote server to our dev environment
every second hour.

_The deploy user needs to have passwordless access to the remote host._

Simply add a new task similar to this (check to make sure it works first!) for
the deploy user.

```sh
$ sudo su deploy
$ crontab -e

0 */2 * * * rsync --archive --delete --compress --times --rsh=ssh deploy@<REMOTE_HOST>:/home/www/<REMOTE_HOME>/deploy/shared/sites/default/files/private/backup_migrate/ /home/deploy/remote-backups/<SITE_NAME>/
```
