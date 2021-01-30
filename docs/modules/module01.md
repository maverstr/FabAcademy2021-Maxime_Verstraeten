# 1. Project Management


## Tools for developing my Website
I will be listing here the main tools that I used to build my website and the main steps to get to this result.

### MkDocs
A website is usually made out of HTML code. You can either write it yourself, which allows you to basically do anything you want if you take the time, or you can go the easiest route to use a HTML generator from Markdown files.
That's what Mkdocs (short for Make Docs I assume) does ! [MkDocs](https://www.mkdocs.org/) a static site generator that build static HTML sites out of .md files. It is highly customizable and [configurable](https://www.mkdocs.org/user-guide/configuration/) by changing the `mkdocs.yml` file.

Installing MkDocs is pretty much straightforward with a Python package manager such as [pip](https://pypi.org/project/pip/) (natively installed with [Anaconda](https://www.anaconda.com/), an open-source Python distribution):
It is always a good practice to update everything before starting a new project:
`conda update --all`
`conda update python`
`pip install --upgrade pip`
Once done: let's install mkdocs: `pip install mkdocs`


With everything installed, a simple `mkdocs new MyFabAcProject` and there we go, ready to document my cursus! Basically, Markdown files must be placed in the created `docs` folder. Each branch of the folder must have an index.md file which will basically be the main page. The actual tree of navigation can be set in the `mkdocs.yml` file.

To preview the website, the command `mkdocs serve` will create a local dev-server that updates in real-time as changes are made in the source files. The server can obviously be accessed by the classical address localhost:8000 or 127.0.0.1.

To deploy it, `mkdocs build --clean` will generate the html files and remove any stale files that may remain. Note that these generated files should not be pushed directly for version control. GitLab _Continous Integration (CI)_ is the best way to publish the website.
!!!note
    Any dependencies required for MkDocs can be set in a .txt file and `pip install -r myfile.txt` in the continuous integration will do the trick perfectly fine.

#### Theme
Multiple themes exist. I first hesitated between [Bootstrap](https://mkdocs.github.io/mkdocs-bootstrap/) and [Material](https://squidfunk.github.io/mkdocs-material/), finally going for the latter.

The theme is set in the mkdocs.yml file. The font, the color palette, the icon,... can all be set in there as well

##### Extra CSS
To not be limited only by the theme classical palette and styles, one can add an `extra_css:` option in the configuration file and then add a `extra.css` file in the docs folder. In there, I can override the default theme values to customize my website even more.

Here is an example to override some headers:
```CSS
.md-typeset h1 {
  color: lightgreen;
  font-size: 80px;
  font-style: oblique;
}

.md-typeset h2 {
  color: lightgreen;
  font-style: oblique;
}

.md-typeset h3 {
  color: lightgreen;
}
```

### Atom
Writing in all these files can be cumbersome in basic editors. Atom is an open-source text editor that features multiple packages, written by its userbase. Among these packages, one can install themes or other scripts. [Atom](https://atom.io/) is amazing to write Markdown files as it features syntax highlighting and some very useful packages such has:
- Markdown-writer: Provides many keybinds and presets for Markdown-style features such as **bold** and _italic_ (though I first learned how to use them manually in notepad to get the hang of it!).
- Markdown-preview: it creates an auto-updating preview of the markdown file in a separate pane.
- Toolbar: It can be added as an extension of Markdown-writer to show a Toolbar at the top of the document.
- Hey-pane: QoL (Quality of life) package that automatically enlarge the current pane in focus. Once you try it, you never go back.

The cool thing with Atom is you never stop customizing your workspace. You just make it your own as you can change everything yourself.

It also natively features version control GUI for Git (see below) which just makes it a breeze to commit and push any part of your work.

!!!success
    **Atom: 5☆/5☆: would recommend to a friend anytime!**

### Git
Git is a version-control system, meaning that we can track changes in a set of files (who did the change, where and when). Moreover, Git allows multiple branches of a project in parallel (non-linear workflow). This eases the development of a project and the cooperation inside a developer team.

I personally used Git **a lot** in [my personal projects](https://github.com/maverstr). It just makes it super easy to work on multiple computers, work with different people and if you make any mistake, you _always_ just revert back to that last working commit.

Also, it's a nice way to store your different projects online and update them over multiple years (either when you need to make a change or when someone proposes a change: _a pull request_).

For the FabAcademy, we have a dedicated repository per student on GitLab. GitLab is a web-based DevOps tool that provides Git-repository but also features issue tracking, continuous integration and deployment pipelines which makes it possible to build our website and publish it on Git.

This week's assignment was also to work through a git Tutorial. As I said before, I have used Git a lot before so I have already a bit of knowledge about it but let's note here the most important commands and some things that I learned.

Git commands can be run either through a GUI (Git Tower, Kraken, Git-Cola, Guitar, ...) or through a command-line interpreter (Git Bash). I personally prefer the latter but I got to admit when you have a lot going on, being able to easily commit chunks of your code independently in a GUI of the rest is very useful.

TODO

### Adding SSH authentication
In order to secure the connection, I used the **SSH protocol** that GitLab provides. This option allows to authenticate to the GitLab remote server without having to enter my login details every time I'm trying to push my work.


The SSH (or Secure Shell) protocol uses _public-key (or asymmetric) cryptography_, meaning that with my public key (accessible to anyone I share it with, and I don't care who I share it with), everyone can encrypt a message that only me will be able to decrypt using my very secret very personal private key.

With my public key, GitLab can encrypt a message for me, that I can decrypt (as I have the corresponding private key) and I can send it back for verification. Since only me would be able to decrypt the message, GitLab can be sure that it is me on the other end of the communication, hence, I am authenticated.

#### How ?
First thing first, I need to generate my own pair of keys.

The _SSH-keygen_ is a tool that can create those kind of pairs and the OpenSSH client is natively pre-installed on many operating systems, including Win10.

Multiple types of encryptions exist, among these the most known RSA and the ED25519. The latter is suggested more secure (others are also deprecated like the DSA, as they present security issues) so we'll go on with ED25519 but the process is mostly the same for whatever type of keys.

###### Generating a new key pair

`ssh-keygen -t ed25519 -C "MyKeyName"`
created my pair of keys in the folder of my choice.
I then selected my public key and set it up on my GitLab settings.
It is also possible to use a passphrase to further encode the private key in case it gets divulgated.

###### Listing GitLab as a known host
When connecting to a new host, we first must verify that this host can be trusted.
`ssh -T git@gitlab.fabcloud.org`
We can also consult the SSH host keys fingerprints to further ensure that we are connecting to the host we want but I did not find those fingerprints for the FabAcademy GitLab instance.

Once done, we can use that command again and GitLab should be able to authenticate our identity.

With this, no need to log in for every push.
For increased security, SSH could also be used for 2FA (2-factor authentication).
